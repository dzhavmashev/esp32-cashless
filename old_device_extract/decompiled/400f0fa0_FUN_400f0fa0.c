// Function : FUN_400f0fa0
// Address  : 0x400f0fa0
// Size     : 172 bytes


int FUN_400f0fa0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 != param_1) {
    if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
      param_2 = (int *)*param_2;
    }
    uVar3 = FUN_40184778();
    iVar4 = FUN_400f0f40(param_1,param_2,uVar3);
    return iVar4;
  }
  if (((*(byte *)((int)param_2 + 0xf) & 0x80) != 0) || (*param_2 != 0)) {
    iVar4 = FUN_40184778();
    if (iVar4 == 0) {
      return 1;
    }
    iVar4 = FUN_40184778(param_1);
    iVar1 = FUN_400f0b60(param_1,iVar4 << 1);
    if (iVar1 != 0) {
      piVar5 = param_1;
      if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
        piVar5 = (int *)*param_1;
      }
      iVar2 = FUN_40184778(param_1);
      func_0x4008b4d0((int)piVar5 + iVar2,piVar5,iVar2);
      FUN_40184790(param_1,iVar4 << 1);
      piVar5 = param_1;
      if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
        piVar5 = (int *)*param_1;
      }
      iVar4 = FUN_40184778(param_1);
      *(undefined1 *)((int)piVar5 + iVar4) = 0;
      return iVar1;
    }
  }
  return 0;
}

