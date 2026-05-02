// Function : FUN_400f1288
// Address  : 0x400f1288
// Size     : 80 bytes


bool FUN_400f1288(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  iVar1 = FUN_40184778(param_1);
  iVar2 = FUN_40184778(param_2);
  bVar3 = false;
  if ((param_3 <= (uint)(iVar1 - iVar2)) &&
     (((*(byte *)((int)param_1 + 0xf) & 0x80) != 0 ||
      (param_1 = (int *)*param_1, param_1 != (int *)0x0)))) {
    if (((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) &&
       (param_2 = (int *)*param_2, param_2 == (int *)0x0)) {
      return false;
    }
    iVar1 = func_0x4008c088((int)param_1 + param_3,param_2,iVar2);
    bVar3 = iVar1 == 0;
  }
  return bVar3;
}

