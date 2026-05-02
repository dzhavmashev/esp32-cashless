// Function : FUN_401518e4
// Address  : 0x401518e4
// Size     : 128 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401518e4(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int *piStack_2c;
  
  piStack_2c = &local_30;
  local_30 = 0;
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  while (iVar2 = _DAT_3ffc8fd4, _DAT_3ffc8fd4 != 0) {
    iVar3 = *(int *)(_DAT_3ffc8fd4 + 0x28);
    if (iVar3 == 0) {
      _DAT_3ffc8fd8 = (int *)&DAT_3ffc8fd4;
    }
    if ((*(uint *)(*(int *)(_DAT_3ffc8fd4 + 0x2c) + 0x10) >> 0x13 & 1) == (param_1 & 0xff)) {
      memw();
      _DAT_3ffc8fd4 = iVar3;
      FUN_401518bc();
    }
    else {
      puVar1 = (undefined4 *)(_DAT_3ffc8fd4 + 0x28);
      _DAT_3ffc8fd4 = iVar3;
      *puVar1 = 0;
      *piStack_2c = iVar2;
      piStack_2c = (int *)(iVar2 + 0x28);
    }
  }
  if (local_30 != 0) {
    do {
      iVar2 = *(int *)(local_30 + 0x28);
      *(undefined4 *)(local_30 + 0x28) = 0;
      *_DAT_3ffc8fd8 = local_30;
      _DAT_3ffc8fd8 = (int *)(local_30 + 0x28);
      local_30 = iVar2;
    } while (iVar2 != 0);
    local_30 = 0;
  }
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  return 0;
}

