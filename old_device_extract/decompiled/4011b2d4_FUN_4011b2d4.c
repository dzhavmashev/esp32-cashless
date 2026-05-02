// Function : FUN_4011b2d4
// Address  : 0x4011b2d4
// Size     : 97 bytes


undefined4 FUN_4011b2d4(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("p_state",0xe6,"lanif.c","!= NULL");
  }
  uVar1 = FUN_40184e40(param_1);
  iVar2 = FUN_40101614(uVar1,param_1 + 0xdc);
  if (iVar2 != 0) {
    *(char **)(param_1 + 0xdc) = "D (%x)\n";
  }
  *(undefined1 **)(param_1 + 0xb8) = &LAB_40115d9c;
  *(undefined4 *)(param_1 + 0xc0) = 0x4011dcc4;
  *(undefined4 *)(param_1 + 0xbc) = 0x4011b204;
  *(undefined2 *)(param_1 + 0xe0) = 0x5dc;
  memw();
  *(undefined2 *)(param_1 + 0xea) = 0x6e06;
  memw();
  *(undefined4 *)(param_1 + 0x108) = 0x4011b1f0;
  memw();
  return 0;
}

