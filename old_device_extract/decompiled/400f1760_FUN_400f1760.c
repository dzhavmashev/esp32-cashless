// Function : FUN_400f1760
// Address  : 0x400f1760
// Size     : 74 bytes


void FUN_400f1760(undefined4 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar1 = FUN_40184778(param_1);
  if ((param_2 < uVar1) && (param_3 != 0)) {
    uVar5 = uVar1 - param_2;
    iVar2 = (uVar5 < param_3) * uVar5 + (uVar5 >= param_3) * param_3;
    puVar4 = param_1;
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      puVar4 = (undefined4 *)*param_1;
    }
    iVar3 = uVar1 - iVar2;
    func_0x4008b4d0((int)puVar4 + param_2,(int)puVar4 + param_2 + iVar2,iVar3 - param_2);
    FUN_40184790(param_1,iVar3);
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      param_1 = (undefined4 *)*param_1;
    }
    *(undefined1 *)((int)param_1 + iVar3) = 0;
  }
  return;
}

