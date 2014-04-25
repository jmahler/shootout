
#include <sys/inotify.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_EVENTS 	1024
#define BUF_SZ 		(MAX_EVENTS*(sizeof(struct inotify_event)))

int notify;
int wd;

void null_handler() {};

int main(int argc, char *argv[])
{
	char *file;
	uint8_t buf[BUF_SZ];
	struct inotify_event *event;
	int len;
	int i;
	int n;
	struct sigaction quit_act;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <file or dir>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = argv[1];

	notify = inotify_init1(0);
	if (-1 == notify) {
		error(1, errno, "inotify_init1 failed");
	}

	if ((wd = inotify_add_watch(notify, file, IN_ALL_EVENTS)) == -1) {
		error(1, errno, "inotify_add_watch of '%s' failed", file);
	}

	memset(&quit_act, 0, sizeof(quit_act));
	quit_act.sa_handler = null_handler;
	sigaction(SIGINT, &quit_act, 0);

	while (1) {

		if ((len = read(notify, buf, BUF_SZ)) < 0) {
			if (errno == EINTR)
				break;

			error(1, errno, "read(notify) failed");
		}

		printf("---\n");
		i = 0;
		n = 1;
		while (i < len) {
			event = (struct inotify_event *) &buf[i];

			printf("%d: ", n++);
			if (event->len) {
				printf("%s", event->name);
			} else {
				printf("(dir)");
			}
			printf("\n");

			/* see inotify(7) for a list of these events */
			if (event->mask & IN_ACCESS)
				printf("IN_ACCESS\n");
			if (event->mask & IN_ATTRIB)
				printf("IN_ATTRIB\n");
			if (event->mask & IN_CLOSE_WRITE)
				printf("IN_CLOSE_WRITE\n");
			if (event->mask & IN_CLOSE_NOWRITE)
				printf("IN_CLOSE_NOWRITE\n");
			if (event->mask & IN_CREATE)
				printf("IN_CREATE\n");
			if (event->mask & IN_DELETE)
				printf("IN_DELETE\n");
			if (event->mask & IN_DELETE_SELF)
				printf("IN_DELETE_SELF\n");
			if (event->mask & IN_MODIFY)
				printf("IN_MODIFY\n");
			if (event->mask & IN_MOVE_SELF)
				printf("IN_MOVE_SELF\n");
			if (event->mask & IN_MOVED_FROM)
				printf("IN_MOVED_FROM\n");
			if (event->mask & IN_MOVED_TO)
				printf("IN_MOVED_TO\n");
			if (event->mask & IN_OPEN)
				printf("IN_OPEN\n");
			if (event->mask & IN_MOVE)
				printf("IN_MOVE\n");
			if (event->mask & IN_CLOSE)
				printf("IN_CLOSE\n");

			i += sizeof(struct inotify_event) + event->len;
		}
	}

	inotify_rm_watch(notify, wd);
	close(wd);
	close(notify);

	return EXIT_SUCCESS;
}
