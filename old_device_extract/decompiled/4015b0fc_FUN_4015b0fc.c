// Function : FUN_4015b0fc
// Address  : 0x4015b0fc
// Size     : 46 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b0fc(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = _DAT_3ffbfdf0;
  if (_DAT_3ffbfdf0 + 4 != 0) {
    pcVar2 = *(code **)(_DAT_3ffbfdf0 + 0x18);
    (*(code *)&SUB_4008b530)(_DAT_3ffbfdf0 + 4,0,0x18);
    *(undefined1 *)(iVar1 + 4) = 0xff;
    memw();
    if (pcVar2 != (code *)0x0) {
      memw();
      (*pcVar2)(*(undefined4 *)(iVar1 + 0x10),param_1);
    }
  }
  return;
}

