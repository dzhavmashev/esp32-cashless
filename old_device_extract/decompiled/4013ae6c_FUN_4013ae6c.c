// Function : FUN_4013ae6c
// Address  : 0x4013ae6c
// Size     : 214 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013ae6c(byte *param_1,uint param_2,uint param_3,undefined1 *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uStack_68;
  byte abStack_64 [64];
  uint uStack_24;
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b530)(abStack_64,0,0x40);
  uStack_68 = 0;
  memw();
  uVar1 = FUN_401864c4(*param_5);
  do {
    if (param_2 != 0) goto LAB_4013aec7;
    iVar2 = 0;
    do {
      memw();
      FUN_4013ae54(abStack_64,0x40);
      param_3 = uStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (uStack_24 == _DAT_3ffc5708) {
        return iVar2;
      }
      (*(code *)&SUB_40082ec4)();
      param_4 = &DAT_3ffc5708;
LAB_4013aec7:
      memw();
      iVar2 = FUN_40139114(param_5);
    } while ((((iVar2 != 0) || (iVar2 = FUN_40139174(param_5,param_3,param_4), iVar2 != 0)) ||
             (iVar2 = FUN_40139174(param_5,&uStack_68,4), iVar2 != 0)) ||
            (iVar2 = FUN_401391c4(param_5,abStack_64), iVar2 != 0));
    iVar2 = 0;
    while (pbVar3 = param_1 + iVar2,
          iVar2 != (param_2 < uVar1) * param_2 + (param_2 >= uVar1) * uVar1) {
      pbVar4 = abStack_64 + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar3 = *pbVar4 ^ *pbVar3;
      memw();
      memw();
    }
    param_2 = param_2 - iVar2;
    uStack_68 = CONCAT13(uStack_68._3_1_ + '\x01',(undefined3)uStack_68);
    memw();
    memw();
    param_1 = pbVar3;
  } while( true );
}

