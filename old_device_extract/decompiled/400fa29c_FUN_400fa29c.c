// Function : FUN_400fa29c
// Address  : 0x400fa29c
// Size     : 594 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fa29c(int param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,int param_6)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bVar6;
  int iStack_48;
  undefined1 auStack_44 [29];
  byte bStack_27;
  uint uStack_24;
  
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  if (*(int *)(param_1 + 100) == 1) {
    iStack_48 = 0;
    uVar4 = 0x48;
    if (param_3 != 0x41) {
      uVar4 = param_3;
    }
    memw();
    iVar1 = FUN_400f9c84(param_1,param_2,uVar4,param_4,&iStack_48,auStack_44,0xff,0xff);
    if ((iVar1 == 0) || (iVar1 == 0x1102)) {
      if (param_3 == 0x41) {
        if (iStack_48 == 0) {
          bVar2 = 0;
          bVar6 = 0;
          goto LAB_400fa376;
        }
        iVar1 = FUN_400f9f0c(param_1,param_2,param_4,param_5,param_6);
        if (iVar1 != 0) goto LAB_400fa32a;
        goto LAB_400fa30a;
      }
      if (iStack_48 != 0) {
        memw();
        iVar1 = FUN_400fb998(iStack_48,param_2,param_3,param_4,param_5,param_6,0xff,0xff);
        if (iVar1 == 0) goto LAB_400fa30a;
      }
      iVar3 = *(int *)(param_1 + 0x14);
      memw();
      iVar1 = FUN_400fb29c(iVar3,param_2,param_3,param_4,param_5,param_6,0xff);
      if (iVar1 == 0x110a) {
        if (((*(int *)(iVar3 + 0xc) != -4) && (iVar1 = FUN_400fb4c8(iVar3), iVar1 != 0)) ||
           (iVar1 = FUN_400fc124(param_1 + 0x10), iVar1 != 0)) goto LAB_400fa30c;
        memw();
        iVar1 = FUN_400fb29c(*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6
                             ,0xff);
        param_5 = 0x110a;
        if (iVar1 == 0x110a) goto LAB_400fa390;
      }
      iVar3 = param_6;
      if (iVar1 == 0) goto LAB_400fa3be;
    }
  }
  else {
    iVar1 = 0x1101;
  }
LAB_400fa30c:
  do {
    param_1 = iVar1;
    param_3 = uStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_400fa32a:
    if (*(int *)(iStack_48 + 0xc) - 1U < 0xfffffffe) goto LAB_400fa364;
    memw();
    iVar1 = FUN_400f9c84(param_1,param_2,param_3,param_4,&iStack_48,auStack_44,0xff,0xff);
    if (iVar1 == 0) goto LAB_400fa364;
    uVar5 = 0x134;
    while( true ) {
      (*(code *)&SUB_4008effc)(iVar1,", item)",uVar5,"age.cpp","ock");
LAB_400fa364:
      bVar6 = bStack_27 & 0x7f;
      if ((bStack_27 & 0x7f) != 0) {
        iVar1 = -1;
        goto LAB_400fa30c;
      }
      bVar2 = bStack_27;
      if (bStack_27 != 0x80) {
        bVar6 = 0x80;
      }
LAB_400fa376:
      memw();
      iVar1 = FUN_400f9cd4(param_1,param_2,param_4,param_5,param_6,bVar6);
      iVar3 = iStack_48;
      param_5 = 0x110a;
      if (iVar1 == 0x110a) goto LAB_400fa390;
      if (iVar1 != 0) goto LAB_400fa30c;
      param_6 = iVar3;
      if (iStack_48 == 0) {
        memw();
        iVar1 = FUN_400f9c84(param_1,param_2,0x41,param_4,&iStack_48,auStack_44,0xff,0xff);
        if ((iVar1 != 0) && (param_5 = (uint)(iVar1 != 0x1102), param_5 != 0)) goto LAB_400fa30c;
      }
      else {
        iVar1 = FUN_400fa000(param_1,param_2,param_4,bVar2);
        param_5 = 0x6001;
        if (iVar1 == 0x6001) goto LAB_400fa4dd;
        if (iVar1 != 0) goto LAB_400fa30c;
        iStack_48 = 0;
      }
LAB_400fa3be:
      param_5 = 0;
      param_6 = iVar3;
      if (iStack_48 == 0) goto LAB_400fa30a;
      param_5 = *(int *)(iStack_48 + 0xc) - 1;
      if (param_5 < 0xfffffffe) break;
      memw();
      iVar1 = FUN_400f9c84(param_1,param_2,param_3,param_4,&iStack_48,auStack_44,0xff,0xff);
      param_5 = 0xff;
      param_6 = -3;
      if (iVar1 == 0) break;
      uVar5 = 0x182;
    }
    iVar1 = FUN_400fbaa4(iStack_48,param_2,param_3,param_4,0xff);
    param_6 = -3;
    iVar3 = param_6;
    if (iVar1 == 0x6001) {
LAB_400fa4dd:
      param_6 = iVar3;
      iVar1 = 0x1108;
    }
  } while( true );
LAB_400fa390:
  param_5 = 0x110a;
  iVar1 = 0x1105;
  goto LAB_400fa30c;
LAB_400fa30a:
  iVar1 = 0;
  goto LAB_400fa30c;
}

