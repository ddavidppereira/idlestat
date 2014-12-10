#ifndef __REPORT_OPS_H
#define __REPORT_OPS_H

struct program_options;
struct cpuidle_cstate;
struct cpufreq_pstate;
struct wakeup_irq;

struct report_ops {
	int (*check_output)(struct program_options *, void *);

	int (*open_report_file)(char *path, void *);
	int (*close_report_file)(void *);

	void (*cstate_table_header)(void *);
	void (*cstate_table_footer)(void *);
	void (*cstate_cpu_header)(const char *cpu, void *);
	void (*cstate_single_state)(struct cpuidle_cstate*, void *);
	void (*cstate_end_cpu)(void *);

	void (*pstate_table_header)(void *);
	void (*pstate_table_footer)(void *);
	void (*pstate_cpu_header)(const char *cpu, void *);
	void (*pstate_single_state)(struct cpufreq_pstate*, void *);
	void (*pstate_end_cpu)(void*);

	void (*wakeup_table_header)(void *);
	void (*wakeup_table_footer)(void *);
	void (*wakeup_cpu_header)(const char *cpu, void *);
	void (*wakeup_single_state)(struct wakeup_irq *irqinfo, void *);
	void (*wakeup_end_cpu)(void *);
};

extern struct report_ops default_report_ops;
extern struct report_ops csv_report_ops;
extern struct report_ops boxless_report_ops;

#endif
