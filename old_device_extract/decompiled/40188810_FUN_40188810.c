// Function : FUN_40188810
// Address  : 0x40188810
// Size     : 266 bytes


undefined4 FUN_40188810(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = 4;
  uVar2 = (*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 8 & 0xf) - 1 & 0xff;
  iVar3 = *(int *)(param_1 + 0x24);
  if (uVar2 < 4) {
    uVar1 = (uint)*(byte *)((int)&PTR_LAB_3f424554 + uVar2);
  }
  puVar5 = *(uint **)(param_1 + 8);
  uVar4 = uVar1 + *(ushort *)(param_1 + 0x16);
  memw();
  uVar2 = *puVar5;
  *(short *)(param_1 + 0x16) = (short)uVar4;
  memw();
  memw();
  memw();
  *puVar5 = *puVar5 & 0xff000fff | ((uVar2 >> 0xc & 0xfff) + uVar1 & 0xfff) << 0xc;
  if ((**(uint **)(param_1 + 0x2c) & 0x40000) == 0) {
    memw();
    memw();
    *puVar5 = *puVar5 | 0x40000000;
    memw();
  }
  else {
    if (iVar3 == 0) {
      return 1;
    }
    puVar5 = *(uint **)(param_1 + 4);
    memw();
    memw();
    *puVar5 = *puVar5 | 0x20000000;
    uVar1 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x10);
    if (((uVar1 & 0xf00) != 0x300) && ((uVar1 & 0xb00) != 0)) {
      memw();
      FUN_40147fe4(6,0x800,1,"!!!!!!\n","s_func_app.c",0xe7f);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar2 = (uVar4 & 0xffff) + (*(ushort *)(param_1 + 0x14) - 4) & 0xfff;
    puVar5 = (uint *)puVar5[1];
    *puVar5 = *puVar5 & 0xfffff000 | uVar2;
    uVar1 = 0;
    uVar4 = (uint)*(ushort *)(iVar3 + 0x7e);
    if (uVar2 + 3 < uVar4) {
      uVar1 = uVar4 - uVar2 >> 2 & 0x7f;
    }
    *puVar5 = *puVar5 & 0xffc80fff | uVar1 << 0xc;
  }
  memw();
  return 0;
}

