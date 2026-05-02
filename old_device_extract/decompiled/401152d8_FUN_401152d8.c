// Function : FUN_401152d8
// Address  : 0x401152d8
// Size     : 182 bytes


undefined4 FUN_401152d8(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0xf0;
  }
  if ((*(byte *)(param_1 + 0xeb) & 1) == 0) {
    return 0xf0;
  }
  iVar3 = *(int *)(param_1 + 200);
  if (0x23f < *(ushort *)(param_1 + 0xe0)) {
    if (iVar3 == 0) {
      iVar3 = FUN_4010af90(0x58);
      if (iVar3 == 0) {
        return 0xff;
      }
      *(int *)(param_1 + 200) = iVar3;
    }
    else if (*(char *)(iVar3 + 4) != '\0') {
      FUN_4011437c();
    }
    memw();
    (*(code *)&SUB_4008b530)(iVar3,0,0x58);
    cVar1 = FUN_401143bc();
    if (cVar1 == '\0') {
      *(undefined1 *)(iVar3 + 4) = 1;
      memw();
      if ((*(byte *)(param_1 + 0xeb) & 4) == 0) {
        memw();
        FUN_4018541c(iVar3,2);
        return 0;
      }
      iVar2 = FUN_4011b138(param_1);
      if (iVar2 != 0) {
        FUN_4018541c(iVar3,10);
        FUN_40115008(param_1);
        return 0;
      }
      if (*(char *)(iVar3 + 8) != '\0') {
        FUN_40113304(&DAT_40115654,param_1);
        *(undefined1 *)(iVar3 + 8) = 0;
        memw();
      }
      memw();
      cVar1 = FUN_40114954(param_1);
      if (cVar1 == '\0') {
        return 0;
      }
      FUN_4011519c(param_1);
    }
  }
  return 0xff;
}

