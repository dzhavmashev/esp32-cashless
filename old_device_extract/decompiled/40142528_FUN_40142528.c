// Function : FUN_40142528
// Address  : 0x40142528
// Size     : 129 bytes


undefined4
FUN_40142528(undefined4 param_1,int param_2,uint *param_3,char *param_4,int param_5,byte *param_6,
            byte *param_7)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  
  uVar6 = *param_3;
  uVar4 = 0xffffffdc;
  if (uVar6 < 0x10) {
    pbVar5 = param_7 + param_2;
    while (param_7 != pbVar5) {
      if (uVar6 == 0) {
        memw();
        FUN_401421e8(param_1,1,param_4,param_5);
        pcVar8 = param_4 + 0xf;
        do {
          cVar2 = *pcVar8;
          *pcVar8 = cVar2 + '\x01';
          memw();
          if ((char)(cVar2 + '\x01') != '\0') break;
          bVar1 = param_4 != pcVar8;
          pcVar8 = pcVar8 + -1;
        } while (bVar1);
      }
      pbVar7 = (byte *)(param_5 + uVar6);
      bVar3 = *param_6;
      uVar6 = uVar6 + 1 & 0xf;
      param_6 = param_6 + 1;
      *param_7 = *pbVar7 ^ bVar3;
      memw();
      param_7 = param_7 + 1;
      memw();
    }
    *param_3 = uVar6;
    uVar4 = 0;
  }
  memw();
  return uVar4;
}

