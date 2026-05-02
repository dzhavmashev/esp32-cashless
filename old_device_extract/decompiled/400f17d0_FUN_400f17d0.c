// Function : FUN_400f17d0
// Address  : 0x400f17d0
// Size     : 129 bytes


void FUN_400f17d0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = param_1;
  if ((((*(byte *)((int)param_1 + 0xf) & 0x80) != 0) ||
      (puVar6 = (undefined4 *)*param_1, puVar6 != (undefined4 *)0x0)) &&
     (iVar1 = FUN_40184778(param_1), puVar5 = puVar6, iVar1 != 0)) {
    while (iVar2 = func_0x4008af54(*(undefined1 *)puVar5), iVar2 != 0) {
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    for (puVar3 = (undefined4 *)((int)puVar6 + iVar1 + -1);
        (iVar1 = func_0x4008af54(*(undefined1 *)puVar3), iVar1 != 0 && (puVar5 <= puVar3));
        puVar3 = (undefined4 *)((int)puVar3 + -1)) {
    }
    puVar4 = (undefined1 *)((int)puVar3 + (1 - (int)puVar5));
    if (puVar6 < puVar5) {
      func_0x4008b4d0(puVar6,puVar5,puVar4);
    }
    FUN_40184790(param_1,puVar4);
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      param_1 = (undefined4 *)*param_1;
    }
    *(undefined1 *)((int)param_1 + (int)puVar4) = 0;
  }
  return;
}

