// Function : FUN_40106c44
// Address  : 0x40106c44
// Size     : 189 bytes


undefined4 FUN_40106c44(undefined4 param_1,undefined1 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (param_3 == (undefined1 *)0x0) {
    uVar4 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"t_timer",&DAT_3f40f2e4,uVar4,"t_timer");
    uVar4 = 0x102;
  }
  else {
    puVar5 = (undefined4 *)(*(code *)&SUB_40094d60)(0x10);
    if (puVar5 == (undefined4 *)0x0) {
      uVar4 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"t_timer","s NULL\n",uVar4,"t_timer");
    }
    else {
      uVar1 = param_3[1];
      *(undefined1 *)((int)puVar5 + 0xb) = *param_3;
      memw();
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *puVar5 = param_1;
      *(undefined1 *)((int)puVar5 + 0xe) = uVar3;
      DAT_3ffc5894 = 1;
      memw();
      *(undefined1 *)(puVar5 + 1) = param_2;
      *(undefined1 *)(puVar5 + 3) = uVar1;
      *(undefined1 *)((int)puVar5 + 0xd) = uVar2;
      memw();
      memw();
      iVar6 = (*(code *)&SUB_4009092c)(0x40106944,"c fail\n",0x800,puVar5,2,0,0x7fffffff);
      if (iVar6 == 1) {
        return 0;
      }
      uVar4 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"t_timer","nd_task",uVar4,"t_timer");
      (*(code *)&SUB_40094d80)(puVar5);
    }
    uVar4 = 0x101;
  }
  return uVar4;
}

