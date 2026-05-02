// Function : FUN_400f867c
// Address  : 0x400f867c
// Size     : 212 bytes


int FUN_400f867c(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  (*(code *)&SUB_4008b530)(param_1,0,0x104);
  *param_1 = param_2;
  puVar3 = param_1 + 1;
  memw();
  iVar1 = FUN_400f8574(param_2,puVar3,0x18,1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_4 == 0) {
LAB_400f8740:
    param_1[0x37] = 0x18;
    memw();
    iVar1 = 0;
  }
  else {
    if ((*(char *)((int)param_1 + 0x1b) != '\0') && (param_3 != (int *)0x0)) {
      iVar1 = FUN_400f8b2c();
      *param_3 = iVar1;
      if (iVar1 == 0) {
        return 0x101;
      }
      memw();
      FUN_400f8b50(iVar1,puVar3,0x18);
    }
    uVar4 = *param_1;
    if (*(char *)(param_1 + 1) == -0x17) {
      iVar1 = FUN_400f8390(puVar3,1);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (*(byte *)((int)param_1 + 5) < 0x11) goto LAB_400f8740;
      if (param_5 == 0) {
        uVar2 = (*(code *)&SUB_40094b80)();
        memw();
        FUN_4012113c(1,"_common","here?)\n",uVar2,"_common",uVar4,*(undefined1 *)((int)param_1 + 5),
                     0x10);
      }
    }
    else if (param_5 == 0) {
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"_common","d 0x%x\n",uVar2,"_common",uVar4);
    }
    iVar1 = 0x2002;
  }
  return iVar1;
}

