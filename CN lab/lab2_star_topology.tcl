set ns [new Simulator]

#Create the trace files
set tracefile [open out.tr w]
$ns trace-all $tracefile

# Create the nam files
set namfile [open out.nam w]
$ns namtrace-all $namfile

proc finish {} {
global ns tracefile namfile
$ns flush-trace
close $namfile
exec nam out.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
#set n5 [$ns node]

#star topology
$ns duplex-link $n0 $n2 10Mb 10ms DropTail
$ns duplex-link $n0 $n1 10Mb 10ms DropTail
$ns duplex-link $n0 $n3 10Mb 10ms DropTail
$ns duplex-link $n0 $n4 10Mb 10ms DropTail

$ns queue-limit $n0 $n3 5
$ns queue-limit $n0 $n2 5
$ns queue-limit $n0 $n1 5
$ns queue-limit $n0 $n1 2

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n0 $n1 orient right-up
$ns duplex-link-op $n0 $n3 orient left-down
$ns duplex-link-op $n0 $n4 orient left-up




set tcp [new Agent/TCP]
$ns attach-agent $n1 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
$tcp set packetSize_ 552

set tcp1 [new Agent/TCP]
$ns attach-agent $n2 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 2
$tcp1 set packetSize_ 552

set tcp2 [new Agent/TCP]
$ns attach-agent $n1 $tcp2
set sink2 [new Agent/TCPSink]
$ns attach-agent $n2 $sink2
$ns connect $tcp2 $sink2
$tcp2 set fid_ 3
$tcp2 set packetSize_ 552

set tcp3 [new Agent/TCP]
$ns attach-agent $n3 $tcp3
set sink3 [new Agent/TCPSink]
$ns attach-agent $n4 $sink3
$ns connect $tcp3 $sink3
$tcp3 set fid_ 4
$tcp3 set packetSize_ 552

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $tcp2
$cbr set packetSize_ 1000
$cbr set rate_ 0.2Mb
$cbr set random_ false

$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 1.5 "$ftp1 start"
$ns at 4.0 "$ftp1 stop"
$ns at 5.0 "$ftp stop"
$ns at 5.5 "$cbr stop"
$ns at 6.0 "finish"

#Print CBR packet size and interval
puts "CBR packet size = [$cbr set packet_size_]"
puts "CBR interval = [$cbr set interval_]"

$ns run
