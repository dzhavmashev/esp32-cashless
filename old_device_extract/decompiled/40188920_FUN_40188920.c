// Function : FUN_40188920
// Address  : 0x40188920
// Size     : 83 bytes


void FUN_40188920(int param_1)

{
  undefined2 uVar1;
  uint *puVar2;
  int iVar3;
  
  puVar2 = *(uint **)(param_1 + 0x2c);
  if ((*puVar2 & 0x80000) == 0) {
    uVar1 = 0;
    if ((*puVar2 & 0x402) == 0) {
      uVar1 = FUN_40163ea4((char)puVar2[3]);
    }
  }
  else {
    uVar1 = FUN_40163f08((char)puVar2[3]);
  }
  *(undefined2 *)((int)puVar2 + 10) = uVar1;
  memw();
  iVar3 = *(int *)(param_1 + 0x2c);
  memw();
  uVar1 = FUN_40163ebc(*(undefined1 *)(iVar3 + 0xc),
                       *(short *)(param_1 + 0x16) + *(short *)(param_1 + 0x14),
                       *(undefined2 *)(iVar3 + 10));
  *(undefined2 *)(iVar3 + 0xe) = uVar1;
  memw();
  memw();
  return;
}

