// Function : FUN_400e7630
// Address  : 0x400e7630
// Size     : 141 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e7630(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [20];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if ((*(char *)(param_1 + 3) != '\0') && (iVar1 = FUN_400da4f0(*param_1), iVar1 != 0)) {
    FUN_400e726c(auStack_44,param_1);
    if (param_1[6] != 0) {
      (*(code *)param_1[7])(param_1 + 4,auStack_44);
    }
    FUN_400e72e8(param_1,auStack_44);
    param_1[2] = param_1[2] + 1;
    FUN_400f06a4(0x3ffc5490,"i_bssid");
    FUN_400f0a50(auStack_38);
  }
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_38);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

