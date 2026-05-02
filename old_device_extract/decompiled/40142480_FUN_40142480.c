// Function : FUN_40142480
// Address  : 0x40142480
// Size     : 167 bytes


undefined4
FUN_40142480(undefined4 param_1,int param_2,int param_3,uint *param_4,int param_5,byte *param_6,
            byte *param_7)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar4 = *param_4;
  uVar3 = 0xffffffdc;
  if (uVar4 < 0x10) {
    pbVar2 = param_7 + param_3;
    if (param_2 == 0) {
      while (pbVar2 != param_7) {
        if (uVar4 == 0) {
          memw();
          FUN_401421e8(param_1,1,param_5,param_5);
        }
        pbVar5 = (byte *)(param_5 + uVar4);
        uVar4 = uVar4 + 1 & 0xf;
        bVar1 = *param_6;
        param_6 = param_6 + 1;
        *param_7 = bVar1 ^ *pbVar5;
        param_7 = param_7 + 1;
        *pbVar5 = bVar1;
        memw();
      }
    }
    else {
      while (param_7 != pbVar2) {
        if (uVar4 == 0) {
          memw();
          FUN_401421e8(param_1,1,param_5,param_5);
        }
        pbVar5 = (byte *)(param_5 + uVar4);
        uVar4 = uVar4 + 1 & 0xf;
        bVar1 = *param_6;
        param_6 = param_6 + 1;
        bVar1 = *pbVar5 ^ bVar1;
        *param_7 = bVar1;
        param_7 = param_7 + 1;
        *pbVar5 = bVar1;
        memw();
        memw();
      }
    }
    uVar3 = 0;
    *param_4 = uVar4;
  }
  memw();
  return uVar3;
}

