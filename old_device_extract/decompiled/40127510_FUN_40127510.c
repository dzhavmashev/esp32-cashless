// Function : FUN_40127510
// Address  : 0x40127510
// Size     : 376 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40127510(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_138;
  int iStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined1 auStack_128 [64];
  undefined1 auStack_e8 [64];
  undefined1 auStack_a8 [132];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40128d5c(*(undefined4 *)(param_1 + 8));
  memw();
  iVar2 = FUN_40128d98(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),auStack_a8,
                       auStack_a8 + iVar1);
  if (iVar2 < 0) goto LAB_401275a0;
  uStack_130 = 6;
  uStack_12c = 6;
  memw();
  iVar2 = (*(code *)&SUB_4008b33c)(param_2,param_3);
  iStack_138 = param_2;
  iStack_134 = param_3;
  if (iVar2 < 1) goto LAB_401275ba;
  while( true ) {
    memw();
    iVar2 = FUN_401857b8(iVar1);
    (*(code *)&SUB_4008b530)(auStack_128,0,iVar2);
    if ((iVar2 == 0x20) &&
       (iVar2 = FUN_401020e4(auStack_128,0x20,2,&iStack_138,&uStack_130,auStack_e8), -1 < iVar2)) {
      uVar3 = FUN_401857f4(*(undefined4 *)(param_1 + 8));
      memw();
      iVar2 = FUN_40128a18();
      iVar6 = FUN_40128a30(auStack_e8,0x20);
      iVar7 = FUN_40128a58(1);
      if (((((iVar2 != 0) && (iVar6 != 0)) && (iVar7 != 0)) &&
          ((iVar4 = FUN_40128b3c(uVar3,iVar7,iVar2), -1 < iVar4 &&
           (iVar4 = FUN_40128af0(iVar6,iVar2,iVar6), -1 < iVar4)))) &&
         (iVar4 = FUN_40128ad8(iVar6,iVar7,iVar6), -1 < iVar4)) {
        FUN_40126228(iVar6,iVar1);
        iVar4 = FUN_40128d44(*(undefined4 *)(param_1 + 8));
        if (((iVar4 == 0) ||
            (iVar5 = FUN_40128e70(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),iVar6,
                                  iVar4), iVar5 < 0)) ||
           (iVar5 = FUN_40128d98(*(undefined4 *)(param_1 + 8),iVar4,auStack_a8,auStack_a8 + iVar1),
           iVar5 < 0)) {
          FUN_40128d84(iVar4,1);
        }
      }
    }
    else {
      iVar7 = 0;
      iVar6 = 0;
      iVar2 = 0;
    }
    FUN_40128a7c(iVar2,1);
    FUN_40128a7c(iVar6,1);
    FUN_40128a7c(iVar7,0);
LAB_401275a0:
    param_3 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    (*(code *)&SUB_40082ec4)();
    param_1 = &DAT_3ffc5708;
LAB_401275ba:
    memw();
    iStack_138 = param_3;
    iStack_134 = param_2;
  }
  return;
}

