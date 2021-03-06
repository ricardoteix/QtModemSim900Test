//    Copyright (C) 2012  Helmut Kemper - <helmut.kemper@gmail.com>
//                                        <http:://www.kemper.com.br>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as
//    published by the Free Software Foundation, either version 3 of the
//    License, or (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.




/*

AT+CMGF=1
AT+CMGR=20

+CMGR: "REC READ","08197344690","","12/01/01,20:10:43-12"
Hello World! In Brasil, this message can be 128 characters per message

OK




como ler a qualidade de sinal
at+csq
resposta:
+CSQ: n,m
se n = 0 sinal = -115dBm ou mais
     = 1       = -111dBm
     = 2...30  = -(2*n+54)dBm
     = 31      = -52dBm
     = 99      = desconectado ou muito baixo
     
COMO LER O NOME DA OEPRADORA
AT+CSPN?
RESPOSTA
+CSPN: "OPERADORA", N°

COMO LER O NUMERO DE QUEM ESTA LIGANDO
AT+CLCC
RESPOSTA:
+CLCC: 1,1,4,0,0,"99268744",161,""
*/


// Please note, in AT String, '&' is used to capture number to memory ( equivales to exp reg '[\-\+0-9]+' )
//                            '@' is used to capture number to memory ignoring all spaces( equivales to exp reg '((?![\s\t])[\-\+0-9]+)' )
//                            '%' is used to capture quoted String
//                            '$' is used to capture any data, except new line ( equivales to exp reg '^.*?[\r\n]' )
//                            'i' id
//                            'd' day
//                            'D' day
//                            'm' month
//                            'M' month
//                            'y' year
//                            'Y' year
//                            'h' hour
//                            'H' hour
//                            'n' Minute
//                            'N' Minute
//                            's' Second
//                            'S' Second
//                            't' Telefon
//                            'T' Telefon
//                            'g' Message
//                            'G' Message
//                            'u' Status
//                            'U' Status
//                            'z' Time Zone
//                            'Z' Time Zone
//                            'a' Data by User
//                            'A' Data by User
//                            'b' Signal quality dBm 
//                            'B' Signal quality dBm
//                            'p' Signal quality Percent
//                            'P' Signal quality Percent
// Example: "+CMTI: \"SM\",&i", where, '&i' is 'capture number and put in Id address'

#ifndef ModemATList_h
#define ModemATList_h

const String modem_ip_single					 =  "AT+CIPMUX=0\r";//OK
//const String modem_ip_multi						 =  "AT+CIPMUX=1\r";//OK
const String modem_ip_mode_normal				 =  "AT+CIPMODE=0\r";//OK-ERROR
//const String modem_ip_mode_transparent			 =  "AT+CIPMODE=1\r";//OK-ERROR
//const String modem_internet_connect				 =  "AT+CGDCONT=1,\"IP\",\"claro.com.br\"\r";//"AT+CGDCONT=1,\"IP\",\"TIM.BR\",\"0.0.0.0\",0,0\r";//"AT+CGDCONT=1,\"IP\",\"TATA.DOCOMO.INTERNET\",\"10.6.6.6\",0,0\r";//OK-ERROR
//const String modem_internet_connect				 =  "AT+CGDCONT=1,\"IP\",\"TIM.BR\",\"0.0.0.0\",0,0\r";//"AT+CGDCONT=1,\"IP\",\"TATA.DOCOMO.INTERNET\",\"10.6.6.6\",0,0\r";//OK-ERROR
const String modem_internet_connect				 =  "AT+CGDCONT=1,\"IP\",\"zap.vivo.com.br\",\"0.0.0.0\",0,0\r";//"AT+CGDCONT=1,\"IP\",\"TATA.DOCOMO.INTERNET\",\"10.6.6.6\",0,0\r";//OK-ERROR
const String modem_internet_connect_ok           =  "CONNECT\r";
const String modem_internet_dns                  =  "AT+CIICR\r";
//const String modem_interner_connect_password	 =  "ATD*99***1#\r";//"AT+CSTT=\"TATA.DOCOMO.INTERNET\"\r";//OK_ERROR
//const String modem_interner_connect_password	 =  "AT+CSTT=\"claro.com.br\",\"claro\",\"claro\"\r";//OK_ERROR
//const String modem_interner_connect_password	 =  "AT+CSTT=\"tim.br\",\"tim\",\"tim\"\r";//OK_ERROR
const String modem_interner_connect_password	 =  "AT+CSTT=\"zap.vivo.com.br\",\"vivo\",\"vivo\"\r";//OK_ERROR
const String modem_deactive_gprs_dpd			 =  "AT+CIPSHUT\r";//OK-CLOSE OK-ERROR
const String modem_deactive_gprs_dpd_ok			 =  "SHUT OK\r";//OK-CLOSE OK-ERROR

const String modem_connect_host_and_port_1of3	 =  "AT+CIPSTART=\"TCP\",\"";//OK-+CME ERRORn-ALREADY CONNECT-STATE:n-CONNECT FAIL-CONNECT OK
const String modem_connect_host_and_port_2of3	 =  "\",\"";
const String modem_connect_host_and_port_3of3	 =  "\"\r";
const String modem_connect_host_and_port_ok      =  "CONNECT OK\r";

const String modem_start_send_data_over_tcp_udp	 =  "AT+CIPSEND\r";

const String modem_header_get_send_1of3			 =  "GET ";
const String modem_header_get_send_2of3          =  "q";
const String modem_header_get_send_3of3			 =  " HTTP/1.1\r\n";
const String modem_header_host					 =  "Host: ";
const String modem_header_hostString             =  "H";
const String modem_header_hostPort				 =  "p";
const String modem_heafer_connection_alive		 =  "Connection: Keep-Alive\r\n";
const String modem_header_accept				 =  "Accept: */*\r\n";
const String modem_header_connection_close		 =  "Connection: close\r\n\r\n";
const String modem_header_connection_close_ok	 =  "SEND OK\r";

const String modem_header_signal_quality         =  "AT+CSQ\r";
const String modem_header_signal_quality_response=  "+CSQ: &b,&p";

const String modem_header_carrier_number         =  "AT+CLCC\r";
const String modem_header_carrier_number_response=  "+CLCC: &x,&x,&x,&x,&x,\"&t\",&x,\"\"";

const String modem_at_command_general_end_line   =  "\r\n";


//const String modem_sms_read_all					 =  "CMGL=\"ALL\"";
//const String modem_sms_read_by_id				 =  "CMGR=";
//const String modem_sms_new_message				 =  "CNMI:";
//const String modem_modem_status					 =  "CPAS";//0 call ready - 2 unknow - 3 tocando - 4 em ligacao
//const String modem_modem_ring					 =  "RING";
//const String modem_modem_no_carrier				 =  "NO CARRIER";
const String modem_modem_ok						 =  "\r\nOK\r\n";
const String modem_modem_error					 =  "ERROR\r";

const String modem_sms_text_redy_to_send		 =  "> ";

// Comandos de 'echo' on/off faz o modem repetir tudo o que é enviado. 
// Deve ser a primeira coisa envoada ao modem
const String modem_echo_off						 =  "ATE0\r";//OK
//const String modem_echo_on						 =  "ATE1\r";//OK

    #ifndef I_do_not_need_to_send_sms_in_my_program
    
        const String modem_sms_text_mode				 =  "AT+CMGF=1\r";//OK
        const String modem_sms_send_confg_1of2           =  "AT+CMGS=\"";
        const String modem_sms_send_telefon              =  "t";
        const String modem_sms_send_confg_2of2           =  "\"\r";
        const String modem_sms_send_message              =  "g";
        const String modem_sms_read_message              =  "AT+CMGR=";
        const String modem_sms_delete_by_id				 =  "AT+CMGD=";
        const String modem_sms_delete_by_status			 =  "AT+CMGDA=";
//        const String modem_response_sms_read             =  "+CMGR: %u,\"&T\",\"\",\"&Y/&M/&D,&H:&N:&S-&z\"\r";
        
    #endif
    
const String modem_variable_id                       =  "i";
const String modem_variable_status                   =  "S";    
const String modem_bye                               =  ">>";//String(char(0x1A));
const String modem_bye_ok                            =  "SEND OK\r\n";
//const String modem_sms_send_ok                     =  "";

//const String modem_response_no_carrier               =  "NO CARRIER\r";
//const String modem_response_no_dialtone1             =  "NO DIALTONE\r";
//const String modem_response_no_dialtone2             =  "NO DIAL TONE\r";
//const String modem_response_no_answer                =  "NO ANSWER\r";
//const String modem_response_busy                     =  "BUSY\r";
//const String modem_response_cme_error                =  "+CME ERROR\r";
//const String modem_response_error                    =  "ERROR\r";
//const String modem_response_ring                     =  "RING\r";
//const String modem_response_sms                      =  "+CMTI: \"SM\",&I\r";
//const String modem_response_close                    =  "CLOSE\r";
//const String modem_response_closed                   =  "CLOSED\r";

//const String modem_response_connection_failed        =  "CONNECTION FAILED\r";
//const String modem_response_call_ready               =  "Call Ready\r";
//const String modem_response_power_down               =  "NORMAL POWER DOWN\r";

//const String modem_user_response_data				 =  "!data:$A\r";
//const String modem_user_response_telefon			 =  "!telefon:@T\r";
//const String modem_user_response_id					 =  "!id:&I\r";
//const String modem_user_response_message			 =  "!message:$G\r";
//const String modem_user_response_status				 =  "!status:$U\r";
const String modem_rtc_read                          =  "AT+CCLK?\r";
const String modem_rtc_ok                            =  "OK";

#endif
