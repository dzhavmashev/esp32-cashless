// Function : FUN_400e667c
// Address  : 0x400e667c
// Size     : 50 bytes


void FUN_400e667c(uint *param_1,uint param_2)

{
  char *pcVar1;
  
  *param_1 = param_2;
  FUN_400f1960(param_2 & 0xff,1);
  pcVar1 = "";
  if ((char)param_1[3] != '\0') {
    pcVar1 = "_ACTIVE";
  }
  FUN_400f06a4(0x3ffc5490,"omplete",*param_1,pcVar1);
  FUN_400f0780(0x3ffc5490,"larity\n");
  return;
}

