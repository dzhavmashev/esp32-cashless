// Function : FUN_400f9f0c
// Address  : 0x400f9f0c
// Size     : 243 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f9f0c(undefined4 param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint in_t0;
  uint uStack_64;
  uint uStack_58;
  undefined4 uStack_48;
  undefined1 auStack_44 [3];
  byte bStack_41;
  uint uStack_2c;
  byte bStack_28;
  byte bStack_27;
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  uStack_48 = 0;
  memw();
  uVar1 = FUN_400f9c84(param_1,param_2,0x48,param_3,&uStack_48,auStack_44,0xff,0xff);
  uVar4 = param_5;
  uVar2 = uVar1;
  if (uVar1 != 0) goto LAB_400f9fa1;
  uVar2 = 0x1118;
  if (uStack_2c != param_5) goto LAB_400f9fa1;
  uStack_58 = (uint)bStack_28;
  uStack_64 = (uint)bStack_27;
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar4 = uVar5 & 0xff;
    uVar2 = uVar1;
    if (uVar4 < uStack_58) {
      uVar4 = uStack_64 + uVar4 & 0xff;
      memw();
      uVar2 = FUN_400f9c84(param_1,param_2,0x42,param_3,&uStack_48,auStack_44,uVar4,0xff);
      uVar6 = 0xff;
      if (uVar2 == 0) goto LAB_400f9fbc;
      if (uVar2 != 0x1102) goto LAB_400f9fa1;
    }
    if (uVar3 == param_5) goto LAB_400f9fa1;
    do {
      uVar2 = 0xffffffff;
LAB_400f9fa1:
      do {
        uVar5 = in_t0;
        param_2 = uVar2;
        param_3 = uStack_24;
        uVar3 = _DAT_3ffc5708;
        memw();
        memw();
        if (uStack_24 == _DAT_3ffc5708) {
          return;
        }
        (*(code *)&SUB_40082ec4)();
        uVar6 = uVar5;
        in_t0 = uVar5;
LAB_400f9fbc:
        memw();
        uVar2 = FUN_400fb998(uStack_48,param_2,0x42,param_3,param_4 + uVar3,uStack_2c & 0xffff,uVar4
                             ,uVar6);
      } while (uVar2 != 0);
      uVar4 = uStack_64 + uVar5;
    } while (bStack_41 != uVar4);
    uVar5 = uVar5 + 1;
    uVar3 = uVar3 + (uStack_2c & 0xffff);
  } while( true );
}

