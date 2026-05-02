// Function : FUN_400fc7ac
// Address  : 0x400fc7ac
// Size     : 71 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400fc7ac(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar2 = (int *)(*(code *)&SUB_40094d60)(0xc);
  uVar3 = 0xc;
  if (piVar2 != (int *)0x0) {
    (*(code *)&SUB_40092a98)(0x3ffbdcd4,0xffffffff);
    piVar1 = _DAT_3ffc56ec;
    iVar4 = 1;
    if (_DAT_3ffc56ec != (int *)0x0) {
      iVar4 = *_DAT_3ffc56ec + 1;
    }
    *param_1 = iVar4;
    _DAT_3ffc56ec = piVar2;
    *piVar2 = iVar4;
    piVar2[1] = param_2;
    piVar2[2] = (int)piVar1;
    memw();
    (*(code *)&SUB_40092bec)(0x3ffbdcd4);
    uVar3 = 0;
  }
  return uVar3;
}

