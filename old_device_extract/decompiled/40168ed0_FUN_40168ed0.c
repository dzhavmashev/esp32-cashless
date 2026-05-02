// Function : FUN_40168ed0
// Address  : 0x40168ed0
// Size     : 169 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40168ed0(void)

{
  ushort uVar1;
  code *pcVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 uVar5;
  undefined2 local_30 [24];
  
  (**(code **)(_DAT_3ffc7e64 + 0xc0))();
  (**(code **)(_DAT_3ffc7e64 + 0xd8))(_DAT_3ffc073c,_DAT_3ffc073e);
  pcVar2 = *(code **)(_DAT_3ffc7e64 + 0xb8);
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1);
  (*pcVar2)(1,1,uVar1 | 2);
  puVar3 = (undefined2 *)0x3ffc3898;
  uVar5 = 0;
  puVar4 = (undefined2 *)&DAT_3ffca560;
  while( true ) {
    (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,uVar5);
    (**(code **)(_DAT_3ffc7e64 + 0x118))(local_30);
    *puVar4 = local_30[0];
    memw();
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 4;
    if (puVar3 == (undefined2 *)0x3ffc389e) break;
    uVar5 = *puVar3;
  }
  (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
  (**(code **)(_DAT_3ffc7e64 + 0xc4))();
  _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x1000;
  return;
}

