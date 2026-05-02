// Function : FUN_40151a70
// Address  : 0x40151a70
// Size     : 137 bytes


void FUN_40151a70(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) =
       *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) & 0xfff7ffff |
       (*(uint *)(*(int *)(param_2 + 0x2c) + 0x10) >> 0x13 & 1) << 0x13;
  *(uint *)(param_1 + 0x1c) =
       *(uint *)(param_1 + 0x1c) & 0xfffeffff | (*(uint *)(param_2 + 0x1c) >> 0x10 & 1) << 0x10;
  if ((**(uint **)(param_2 + 0x2c) & 0x4000) != 0) {
    puVar5 = *(undefined1 **)(param_2 + 4);
    puVar4 = *(undefined1 **)(param_1 + 4);
    uVar1 = puVar5[1];
    *puVar4 = *puVar5;
    memw();
    uVar2 = puVar5[2];
    puVar4[1] = uVar1;
    memw();
    uVar1 = puVar5[3];
    puVar4[2] = uVar2;
    puVar4[3] = uVar1;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_2 + 0x2c),0x20);
    *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)(param_2 + 0x14);
    memw();
    uVar3 = *(undefined4 *)(param_2 + 0x24);
    *(undefined2 *)(param_1 + 0x16) = *(undefined2 *)(param_2 + 0x16);
    memw();
    *(undefined4 *)(param_1 + 0x24) = uVar3;
  }
  memw();
  return;
}

