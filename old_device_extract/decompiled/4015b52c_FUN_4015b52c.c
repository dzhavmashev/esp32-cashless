// Function : FUN_4015b52c
// Address  : 0x4015b52c
// Size     : 62 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_4015b52c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _DAT_3ffbfdf0;
  uVar3 = 3;
  if (*(char *)(_DAT_3ffbfdf0 + 4) == -1) {
    *(undefined1 *)(_DAT_3ffbfdf0 + 4) = *param_1;
    memw();
    uVar1 = param_1[1];
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined1 *)(iVar2 + 5) = uVar1;
    memw();
    *(undefined4 *)(iVar2 + 0xc) = param_3;
    *(undefined4 *)(iVar2 + 0x14) = param_4;
    *(undefined4 *)(iVar2 + 0x18) = param_5;
    *(undefined4 *)(iVar2 + 0x10) = param_6;
    memw();
    FUN_4015b458();
    uVar3 = 0;
  }
  return uVar3;
}

