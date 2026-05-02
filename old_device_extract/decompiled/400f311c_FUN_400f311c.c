// Function : FUN_400f311c
// Address  : 0x400f311c
// Size     : 114 bytes


char * FUN_400f311c(undefined4 param_1,undefined4 param_2,char *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar6 = CONCAT44(param_2,param_1);
  uVar5 = (int)param_4 >> 0x1f;
  pcVar4 = param_3;
  if (param_4 - 2 < 0xf) {
    do {
      uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
      uVar1 = (uint)uVar6;
      uVar6 = (*(code *)&SUB_4000cff8)(uVar1,uVar3,param_4,uVar5);
      iVar2 = (*(code *)&SUB_4000d280)(uVar1,uVar3,param_4,uVar5);
      *pcVar4 = "loopTask"[iVar2 + 1];
      pcVar4 = pcVar4 + 1;
      if (uVar3 < uVar5) break;
    } while ((uVar5 != uVar3) || (param_4 <= uVar1));
    (*(code *)&LAB_4018483f_1)(param_3,pcVar4);
    *pcVar4 = '\0';
  }
  else {
    *param_3 = '\0';
  }
  return param_3;
}

