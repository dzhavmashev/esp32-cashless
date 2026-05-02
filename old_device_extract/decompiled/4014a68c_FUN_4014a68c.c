// Function : FUN_4014a68c
// Address  : 0x4014a68c
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014a68c(int *param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  if (7 < param_2) {
    FUN_40147fe4(1,0x400,2,0x3f43669e);
    return;
  }
  iVar1 = param_1[param_2 + 0x91];
  if (iVar1 != 0) {
    uVar2 = 0;
    if (*param_1 != _DAT_3ffc8800) {
      uVar2 = *(undefined1 *)((int)param_1 + 0x26);
    }
    FUN_4015fe1c(uVar2,*(undefined1 *)(iVar1 + 0x2f),0);
    FUN_4014a100(iVar1);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
    param_1[param_2 + 0x91] = 0;
  }
  memw();
  return;
}

