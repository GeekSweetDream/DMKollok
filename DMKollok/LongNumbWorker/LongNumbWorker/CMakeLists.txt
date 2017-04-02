cmake_minimum_required(VERSION 3.7)
project(LongNumbWorker)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        DMKollok/N/ADD_NN_N/ADD_NN_N.c
        DMKollok/N/SUB_NN_N/SUB_NN_N.c
        DMKollok/N/COM_NN_D/COM_NN_D.c
        DMKollok/N/bfunc/bfunc.c
        DMKollok/N/MUL_NN_N/MULL_N_N.c
        DMKollok/N/MUL_Nk_N/MUL_Nk_N.c
        DMKollok/N/MUL_ND_N/MUL_ND_N.c
        DMKollok/N/DIV_NN_N/DIV_NN_N.c
        DMKollok/N/SUB_NDN_N/SUB_NDN_N.c
        DMKollok/N/DIV_NN_Dk/DIV_NN_Dk.c
        DMKollok/N/MOD_NN_N/MOD_NN_N.c
        DMKollok/N/NZER_N_B/NZER_N_B.c
        DMKollok/N/GCF_NN_N/GCF_NN_N.c
        DMKollok/N/LCM_NN_N/main.c
        DMKollok/Z/ADD_ZZ_Z/ADD_ZZ_Z.c
        DMKollok/Z/POZ_Z_D/POZ_Z_D.c
        DMKollok/Z/MUL_ZM_Z/MUL_ZM_Z.c
        DMKollok/Z/ABS_Z_N/ABS_Z_N.c
        DMKollok/Z/SUB_ZZ_Z/SUB_ZZ_Z.c
        DMKollok/Z/MUL_ZZ_Z/MULL_ZZ_Z.c
        DMKollok/Z/DIV_ZZ_Z/DIV_ZZ_Z.c
        DMKollok/Z/TRANS_N_Z/TRANS_N_Z.c
        DMKollok/Z/MOD_ZZ_Z/MOD_ZZ_Z.c
        DMKollok/Z/TRANS_Z_N/TRANS_Z_N.c
        DMKollok/Q/ADD_QQ_Q/ADD_QQ_Q.c
        DMKollok/Q/SUB_QQ_Q/SUB_QQ_Q.c
        DMKollok/Q/MUL_QQ_Q/MUL_QQ_Q.c
        DMKollok/Q/RED_Q_Q/RED_Q_Q.c
        DMKollok/Q/DIV_QQ_Q/DIV_QQ_Q.c
        DMKollok/Q/TRANS_Q_Z/TRANS_Q_Z.c
        DMKollok/Q/TRANS_Z_Q/TRANS_Z_Q.c
        DMKollok/Q/INT_Q_B/INT_Q_B.c
        DMKollok/P/ADD_PP_P/ADD_PP_P.c
        DMKollok/P/SUB_PP_P/SUB_PP_P.c
        DMKollok/P/MUL_PQ_P/MUL_PQ_P.c
        main.c)

add_executable(LongNumbWorker ${SOURCE_FILES})