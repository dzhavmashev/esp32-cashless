// Function : FUN_400e726c
// Address  : 0x400e726c
// Size     : 107 bytes


void FUN_400e726c(uint *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_400f0be8(param_1 + 3,&DAT_3f42161d);
  *(undefined1 *)(param_1 + 7) = 0;
  uVar3 = FUN_400f1a9c();
  *param_1 = uVar3 / 1000;
  uVar3 = FUN_400efe4c(0x3ffc53f4);
  param_1[1] = uVar3;
  cVar1 = FUN_400e979c(&DAT_3ffc516c);
  param_1[2] = (int)cVar1;
  iVar4 = (*(code *)&LAB_40183e8b_1)(param_2[1]);
  pcVar5 = "g state";
  if (iVar4 != 1) {
    pcVar5 = "te";
  }
  FUN_400f0d70(param_1 + 3,pcVar5);
  uVar2 = FUN_400da4f0(*param_2);
  *(undefined1 *)(param_1 + 7) = uVar2;
  return;
}

