// Function : FUN_4012768c
// Address  : 0x4012768c
// Size     : 389 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012768c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iStack_b4;
  int iStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [64];
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40128a30(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc),
                       *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10));
  iVar2 = FUN_40128a30(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14),
                       *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18));
  if (iVar1 == 0) goto LAB_401276ca;
  if (iVar2 == 0) goto LAB_401276ca;
  do {
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10);
    uStack_ac = 6;
    uStack_a8 = 6;
    memw();
    iVar3 = (*(code *)&SUB_4008b33c)(param_2,param_3);
    iStack_b4 = param_2;
    iStack_b0 = param_3;
    if (iVar3 < 1) {
      memw();
      iStack_b4 = param_3;
      iStack_b0 = param_2;
    }
    memw();
    iVar3 = FUN_401857d0(uVar8);
    (*(code *)&SUB_4008b530)(auStack_a4,0,iVar3);
    if ((iVar3 == 0x20) &&
       (iVar3 = FUN_401020e4(auStack_a4,0x20,2,&iStack_b4,&uStack_ac,auStack_64), -1 < iVar3)) {
      iVar7 = FUN_40128a18();
      iVar5 = FUN_40128a30(auStack_64,0x20);
      iVar6 = FUN_40128a58(1);
      if ((iVar7 == 0) || (iVar5 == 0)) {
LAB_401277e6:
        iVar3 = 0;
      }
      else {
        iVar3 = 0;
        if (iVar6 != 0) {
          memw();
          iVar4 = FUN_40128b3c(iVar2,iVar6,iVar7);
          iVar3 = 0;
          if (((-1 < iVar4) && (iVar4 = FUN_40128af0(iVar5,iVar7,iVar5), -1 < iVar4)) &&
             (iVar4 = FUN_40128ad8(iVar5,iVar6,iVar5), -1 < iVar4)) {
            FUN_40126228(iVar5,uVar8);
            iVar3 = FUN_40128a18();
            if ((iVar3 == 0) ||
               (iVar4 = FUN_40128b08(*(undefined4 *)(param_1 + 0x14),iVar5,iVar1,iVar3), iVar4 < 0))
            {
              FUN_40128a7c(iVar3,1);
              goto LAB_401277e6;
            }
            FUN_40126228(iVar3,uVar8);
          }
        }
      }
    }
    else {
LAB_401276ca:
      iVar6 = 0;
      iVar5 = 0;
      iVar7 = 0;
      iVar3 = 0;
    }
    param_1 = iVar3;
    memw();
    FUN_40128a7c(iVar7,1);
    FUN_40128a7c(iVar5,1);
    FUN_40128a7c(iVar6,0);
    FUN_40128a7c(iVar1,0);
    FUN_40128a7c(iVar2,0);
    param_3 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
  } while( true );
}

