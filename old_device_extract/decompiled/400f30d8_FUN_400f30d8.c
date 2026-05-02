// Function : FUN_400f30d8
// Address  : 0x400f30d8
// Size     : 65 bytes


char * FUN_400f30d8(uint param_1,char *param_2,uint param_3)

{
  bool bVar1;
  char *pcVar2;
  
  pcVar2 = param_2;
  if (param_3 - 2 < 0xf) {
    do {
      *pcVar2 = "loopTask"[param_1 % param_3 + 1];
      pcVar2 = pcVar2 + 1;
      bVar1 = param_3 <= param_1;
      param_1 = param_1 / param_3;
    } while (bVar1);
    (*(code *)&LAB_4018483f_1)(param_2,pcVar2);
    *pcVar2 = '\0';
  }
  else {
    *param_2 = '\0';
  }
  return param_2;
}

