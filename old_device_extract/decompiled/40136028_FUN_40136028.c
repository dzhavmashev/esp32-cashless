// Function : FUN_40136028
// Address  : 0x40136028
// Size     : 52 bytes


undefined4 FUN_40136028(undefined4 param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (1 < param_4) {
    pbVar2 = (byte *)*param_3;
    pbVar3 = pbVar2 + 1;
    *param_3 = pbVar3;
    uVar4 = (uint)*pbVar2;
    if ((uVar4 != 0) && (uVar4 <= param_4 - 1)) {
      *param_3 = pbVar3 + uVar4;
      memw();
      uVar1 = FUN_40135f68(param_1,param_2);
      return uVar1;
    }
  }
  return 0xffffb080;
}

