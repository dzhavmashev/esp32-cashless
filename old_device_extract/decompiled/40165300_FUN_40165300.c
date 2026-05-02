// Function : FUN_40165300
// Address  : 0x40165300
// Size     : 105 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40165300(uint *param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *param_1 & 0xfff;
  uVar4 = *param_1 >> 0xc & 0xfff;
  uVar5 = *param_2 & 0xfff;
  if ((uVar3 == uVar4) && (uVar3 != 0)) {
    uVar2 = 1;
    if (uVar3 != uVar5) {
      uVar2 = 2;
    }
    return uVar2;
  }
  uVar4 = uVar4 + 8;
  if (((uVar3 != uVar4) || (uVar2 = 1, uVar3 != uVar5)) && (uVar2 = 2, uVar3 != uVar4)) {
    uVar3 = *param_2 >> 0xc & 0xfff;
    uVar2 = 0;
    if ((uVar5 != uVar3) && (uVar5 != uVar3 + 8)) {
      FUN_40147fe4(6,0x20,2,0x3f437165);
      for (puVar1 = _DAT_3ffc06fc; memw(), (*puVar1 & 0x40000000) == 0; puVar1 = (uint *)puVar1[2])
      {
      }
      return 3;
    }
  }
  return uVar2;
}

