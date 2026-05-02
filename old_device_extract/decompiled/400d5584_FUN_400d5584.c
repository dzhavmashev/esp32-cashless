// Function : FUN_400d5584
// Address  : 0x400d5584
// Size     : 55 bytes


void FUN_400d5584(undefined4 param_1,char param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  
  pcVar3 = " failed";
  do {
    cVar2 = pcVar3[2];
    if (cVar2 == '\0') {
      if (param_2 == '\0') {
        FUN_400d4ac0(param_1,&DAT_3f401ad4);
        return;
      }
      goto LAB_400d55a6;
    }
    pcVar1 = pcVar3 + 3;
    pcVar3 = pcVar3 + 2;
  } while (*pcVar1 != param_2);
  FUN_400d556c(param_1,0x5c);
  param_2 = cVar2;
LAB_400d55a6:
  FUN_400d556c(param_1,param_2);
  return;
}

