The reason why or gate is not functioning correctly is because of the sensitivity 
list of SC_METHOD prc_monitor, since we there isn't a clock, simultaneous changes 
in m_a and m_b (which corresponds to signals(primitive channels) t_a and t_b) in
top module are not registered to t_c at right time.