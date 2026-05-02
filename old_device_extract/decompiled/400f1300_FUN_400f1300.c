// Function : FUN_400f1300
// Address  : 0x400f1300
// Size     : 82 bytes


bool FUN_400f1300(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar1 = FUN_40184778(param_1);
  uVar2 = FUN_40184778(param_2);
  bVar4 = false;
  if ((uVar2 <= uVar1) &&
     (((*(byte *)((int)param_1 + 0xf) & 0x80) != 0 ||
      (param_1 = (int *)*param_1, param_1 != (int *)0x0)))) {
    if (((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) &&
       (param_2 = (int *)*param_2, param_2 == (int *)0x0)) {
      return false;
    }
    iVar3 = func_0x4008bdf4((int)param_1 + (uVar1 - uVar2),param_2);
    bVar4 = iVar3 == 0;
  }
  return bVar4;
}

