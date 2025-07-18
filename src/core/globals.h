/*
 * global variables
 *
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of Kamailio, a free SIP server.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Kamailio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * Kamailio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
/*!
* \file
* \brief Kamailio core :: Global variables
* \ingroup core
* Module: \ref core
*/


#ifndef globals_h
#define globals_h

#include "ip_addr.h"
#include "str.h"
#include "poll_types.h"

#define NO_DNS 0
#define DO_DNS 1
#define DO_REV_DNS 2


extern char *mods_dir;	 /* directory with dyn. loadable modules */
extern int mods_dir_cmd; /* marker if mods dir was set in command line */
extern char *cfg_file;
extern int config_check;
extern char *stat_file;
extern unsigned short port_no;

extern unsigned int
		sr_dst_max_branches; /* max number of branches per transaction */

extern time_t up_since;
extern pid_t creator_pid; /* pid of first process before daemonization */
extern int uid;
extern int gid;
extern char *pid_file;
extern char *pgid_file;
/* whether or not we have our own pgid (and it's ok to use kill(0, sig) */
extern int own_pgid;

extern int server_id; /* A unique ID of the SIP server */

extern struct socket_info *bind_address; /* pointer to the crt. proc.
											listening address */
extern struct socket_info *sendipv4;	 /* ipv4 socket to use when msg
											comes from ipv6 */
extern struct socket_info *sendipv6;	 /* same as above for ipv6 */
#ifdef USE_RAW_SOCKS
extern int raw_udp4_send_sock;
#endif /* USE_RAW_SOCKS */

#ifdef USE_TCP
extern struct socket_info *sendipv4_tcp; /* ipv4 socket to use when msg
											comes from ipv6 */
extern struct socket_info *sendipv6_tcp; /* same as above for ipv6 */
extern int unix_tcp_sock; /* socket used for communication with tcp main */
#endif
#ifdef USE_TLS
extern struct socket_info *sendipv4_tls; /* ipv4 socket to use when msg
											comes from ipv6 */
extern struct socket_info *sendipv6_tls; /* same as above for ipv6 */
#endif
#ifdef USE_SCTP
extern struct socket_info *sendipv4_sctp; /* ipv4 socket to use when msg
											 comes from ipv6 */
extern struct socket_info *sendipv6_sctp; /* same as above for ipv6 */
#endif

extern unsigned int maxbuffer;
extern unsigned int maxsndbuffer;
extern unsigned int sql_buffer_size;
extern int children_no;
extern int socket_workers;
#ifdef USE_TCP
extern int tcp_main_pid;
extern int tcp_cfg_children_no;
extern int tcp_accept_unique;
extern int tcp_connection_match;
extern int tcp_children_no;
extern int tcp_disable;
extern enum poll_types tcp_poll_method;
extern int tcp_max_connections; /* maximum tcp connections, hard limit */
extern int tls_max_connections; /* maximum tls connections, hard limit */
#endif
extern int ksr_tcp_accept_hep3;
extern int ksr_tcp_accept_haproxy;
extern int ksr_tcp_script_mode;
#ifdef USE_TLS
extern int tls_connection_match_domain;
extern int tls_disable;
extern unsigned short tls_port_no;
#define KSR_TLS_THREADS_MNONE 0 /* no set of set thread-local variables */
#define KSR_TLS_THREADS_MTEMP \
	1 /* set thread-local variables in temp thread; deprecated and unused for 6.x */
#define KSR_TLS_THREADS_MFORK 2 /* set thread-local variables in at-fork */
extern int ksr_tls_threads_mode;
#endif
#ifdef USE_SCTP
extern int sctp_disable;
extern int sctp_children_no;
#endif
extern int dont_fork;
extern int dont_daemonize;
extern int check_via;
extern int phone2tel;
extern int received_dns;
extern int child_rank;
extern int sip_warning;
extern int server_signature;
extern str server_hdr;
extern str user_agent_hdr;
extern char *user;
extern char *group;
extern char *sock_user;
extern char *sock_group;
extern int sock_uid;
extern int sock_gid;
extern int sock_mode;
extern char *chroot_dir;
extern char *working_dir;
extern char *runtime_dir;
extern int sr_auto_aliases;
extern int sr_msg_time;
extern str version_table;

#ifdef USE_MCAST
extern int mcast_loopback;
extern int mcast_ttl;
extern char *mcast;
#endif /* USE_MCAST */

extern int auto_bind_ipv6;
extern int sr_bind_ipv6_link_local;

extern int tos;
extern int pmtu_discovery;

extern int cfg_errors;
extern int cfg_warnings;
extern unsigned int msg_no;

extern unsigned long shm_mem_size;
extern unsigned long pkg_mem_size;

/* AVP configuration */
extern char *avp_db_url; /* db url used by user preferences (AVPs) */

extern int reply_to_via;

extern int _ksr_is_main;
extern int fixup_complete;

extern int ksr_mem_add_size;

/* debugging level for dumping memory status */
extern int memlog;
/* debugging level for malloc debugging messages */
extern int memdbg;

/* debugging level for timer debugging (see -DTIMER_DEBUG) */
extern int timerlog;

/* looking up outbound interface ? */
extern int mhomed;

/* command-line arguments */
extern int my_argc;
extern char **my_argv;

/* pre-set addresses */
extern str default_global_address;
/* pre-ser ports */
extern str default_global_port;

/* how much time to allow for shutdown, before killing everything */
extern int ser_kill_timeout;

/* core dump and file limits */
extern int disable_core_dump;
extern int open_files_limit;

/* memory lock/pre-fault */
extern int shm_force_alloc;
extern int mlock_pages;

/* execute onsend_route for replies */
extern int onsend_route_reply;

extern int ksr_evrt_received_mode;
extern str kemi_received_route_callback;
extern str kemi_pre_routing_callback;

/* real time stuff */
extern int real_time;
extern int rt_prio;
extern int rt_policy;		 /* SCHED_OTHER */
extern int rt_timer1_prio;	 /* "fast" timer */
extern int rt_timer2_prio;	 /* "slow" timer */
extern int rt_timer1_policy; /* "fast" timer, SCHED_OTHER */
extern int rt_timer2_policy; /* "slow" timer, SCHED_OTHER */

extern int http_reply_parse;
extern int _sr_ip_free_bind;
extern int ksr_verbose_startup;
extern int ksr_all_errors;
extern int ksr_route_locks_size;
extern str _ksr_xavp_via_params;
extern str _ksr_xavp_via_fields;
extern str _ksr_xavp_via_reply_params;
extern int ksr_sip_parser_mode;
extern int ksr_cfg_print_mode;
extern int ksr_return_mode;

extern int ksr_wait_worker1_mode;
extern int ksr_wait_worker1_time;
extern int ksr_wait_worker1_usleep;
extern int *ksr_wait_worker1_done;

extern char *_sr_uri_host_extra_chars;
extern unsigned char *_ksr_hname_extra_chars;

extern char *ksr_stats_namesep;
extern str ksr_ipv6_hex_style;
extern int ksr_local_rport;

extern int ksr_rpc_exec_delta;

extern int ksr_udp_receiver_mode;
extern int ksr_msg_recv_max_size;
extern int ksr_tcp_msg_read_timeout;
extern int ksr_tcp_msg_data_timeout;
extern int ksr_tcp_accept_iplimit;
extern int ksr_tcp_main_threads;
extern int ksr_tcp_check_timer;

#ifdef USE_DNS_CACHE
extern int
		dns_cache_init; /* if 0, the DNS cache is not initialized at startup */
extern unsigned int dns_timer_interval; /* gc timer interval in s */
extern int dns_flags; /* default flags used for the  dns_*resolvehost
                    (compatibility wrappers) */

#ifdef USE_DNS_CACHE_STATS
struct t_dns_cache_stats
{
	unsigned long dns_req_cnt;
	unsigned long dc_hits_cnt;
	unsigned long dc_neg_hits_cnt;
	unsigned long dc_lru_cnt;
};
extern struct t_dns_cache_stats *dns_cache_stats;
#endif /* USE_DNS_CACHE_STATS */
#endif
#ifdef USE_DST_BLOCKLIST
extern int
		dst_blocklist_init; /* if 0, the dst blocklist is not initialized at startup */
extern unsigned int blst_timer_interval; /*blocklist gc timer interval (in s)*/

#ifdef USE_DST_BLOCKLIST_STATS
struct t_dst_blocklist_stats
{
	unsigned long bkl_hit_cnt;
	unsigned long bkl_lru_cnt;
};
extern struct t_dst_blocklist_stats *dst_blocklist_stats;
#endif /* USE_DST_BLOCKLIST_STATS */
#endif

#endif
