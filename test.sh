
for file in $1/*
do
	echo "\033[1;35m" "--------------------------------"
	echo "\033[1;34m" $file
	var=${file%%.s}
	./asm $var.s &> /dev/null
	if [ -e $var.cor ]
	then
		        one=`md5 $var.cor`
				        rm -f $var.cor
					else
						        one="Error"
							fi
							./vm_champs/asm $var.s &> /dev/null
							if [ -e $var.cor ]
							then
								        two=`md5 $var.cor`
										        rm -f $var.cor
											else
												        two="Error"
													fi
													one=${one##*=}
													two=${two##*=}
													rm -f $var.cor
													if [ $one = $two ]
													then
														        echo "\033[1;32m" OK
																        echo $one
																		        echo $two
																			else
																				        echo "\033[1;31m" KO!
																						        echo $one
																								        echo $two
																									fi
																									#echo $one
																									#echo $two
																								done
