// Function : FUN_40170020
// Address  : 0x40170020
// Size     : 88 bytes


uint * FUN_40170020(uint *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *in_t0;
  
  puVar1 = (undefined4 *)FUN_4017061c();
  puVar2 = param_1 + -0xc;
  puVar3 = (uint *)*puVar1;
  uVar5 = *param_1 + 0xbcd4d500;
  if (((uint)(uVar5 < *param_1) + param_1[1] + 0xb8b1aabc == 0) && (uVar5 < 2)) {
    uVar5 = param_1[-7];
    if ((int)uVar5 < 0) {
      uVar5 = -uVar5;
    }
    param_1[-7] = uVar5 + 1;
    puVar1[1] = puVar1[1] + -1;
    if (puVar3 != puVar2) {
      param_1[-8] = (uint)puVar3;
      *puVar1 = puVar2;
    }
    puVar4 = (uint *)param_1[-2];
  }
  else {
    puVar4 = (uint *)0x0;
    if (puVar3 != (uint *)0x0) {
      puVar2 = in_t0;
      puVar1 = (undefined4 *)FUN_401701ec();
      puVar4 = puVar2;
    }
    *puVar1 = puVar2;
  }
  return puVar4;
}

