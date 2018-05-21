#include <stdio.h>
#include <polysat/polysat.h>

/*
 * The event callback function. Will be called once a second.
 */
int my_timed_event(void *arg)
{
   printf("Hello World\n");
   /* Returning EVENT_KEEP will resechedule the event to run again on the event loop */
   return EVENT_KEEP;
}

int main(void)
{
   /* Where libproc stores its state */
   struct ProcessData *proc;

   /* Initialize the process */
   proc = PROC_init("test1", 0);
   if (!proc) {
      printf("error: failed to initialize process\n");
      return -1;
   }

   /* Schedule my_timed_event to run once a second on the event loop */
   EVT_sched_add(PROC_evt(proc), EVT_ms2tv(1000), &my_timed_event, NULL);

   /* Start the event loop */
   printf("Starting the event loop...\n");
   EVT_start_loop(PROC_evt(proc));

   /* Clean up libproc */
   printf("Cleaning up process...\n");
   PROC_cleanup(proc);

   printf("Done.\n");
   return 0;
}
