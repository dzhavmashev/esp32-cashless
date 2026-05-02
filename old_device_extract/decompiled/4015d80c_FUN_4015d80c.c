// Function : FUN_4015d80c
// Address  : 0x4015d80c
// Size     : 189 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015d80c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  
  iVar2 = _DAT_3ffc8804;
  uVar4 = 1;
  while( true ) {
    if (*(byte *)(_DAT_3ffbfc54 + 0x3f6) < uVar4) {
      return;
    }
    if (*(int *)((uVar4 + 0x38) * 4 + _DAT_3ffc8804 + 0xc) == param_1) break;
    uVar4 = uVar4 + 1 & 0xff;
  }
  memw();
  FUN_4015fdf8(*(undefined1 *)(param_1 + 0x134));
  if (_DAT_3ffc89a4 != 0) {
    (**(code **)(_DAT_3ffc89a4 + 0x28))(*(undefined4 *)(param_1 + 0x130));
  }
  (**(code **)(_DAT_3ffc1a34 + 0xb0))
            (*(undefined4 *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4));
  *(undefined4 *)(&DAT_3ffc87f0 + (*(byte *)(param_1 + 0x134) + 0x50) * 4) = 0;
  memw();
  FUN_40154b3c(param_1);
  FUN_4014b430(param_1);
  (**(code **)(_DAT_3ffc1a34 + 0xb0))(param_1);
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  *(undefined4 *)((uVar4 + 0x38) * 4 + iVar2 + 0xc) = 0;
  uVar1 = _DAT_3ffc799c;
  pcVar3 = *(code **)(_DAT_3ffc1a34 + 0x58);
  *(uint *)(iVar2 + 300) =
       *(uint *)(iVar2 + 300) & (uint)(0xfffffffefffffffe >> 0x20 - (uVar4 & 0x1f));
  memw();
  (*pcVar3)(uVar1);
  return;
}

