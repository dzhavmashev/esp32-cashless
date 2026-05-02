// Function : FUN_4011e684
// Address  : 0x4011e684
// Size     : 159 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_4011e684(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar1 = (uint *)FUN_4011e5bc(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    iVar2 = (*(code *)&SUB_40083fe0)(0xc,0x804);
    puVar1 = (uint *)0x0;
    if (iVar2 != 0) {
      puVar1 = (uint *)(*(code *)&SUB_4008b530)(iVar2,0,0xc);
      *puVar1 = *puVar1 & 0xffc0ffff | (param_1 & 0x1f) << 0x11 | (param_2 & 1) << 0x10;
      puVar3 = (uint *)0x0;
      for (puVar4 = _DAT_3ffc66e0;
          ((puVar4 != (uint *)0x0 && (uVar5 = *puVar4, (uVar5 >> 0x10 & 1) <= (param_2 & 1))) &&
          ((((uVar5 ^ *puVar1) & 0x10000) != 0 || ((uVar5 >> 0x11 & 0x1f) < (param_1 & 0x1f)))));
          puVar4 = (uint *)puVar4[2]) {
        puVar3 = puVar4;
      }
      if ((puVar3 == (uint *)0x0) || (_DAT_3ffc66e0 == (uint *)0x0)) {
        puVar1[2] = (uint)puVar4;
        _DAT_3ffc66e0 = puVar1;
      }
      else {
        puVar3[2] = (uint)puVar1;
        puVar1[2] = (uint)puVar4;
        memw();
      }
    }
  }
  memw();
  return puVar1;
}

