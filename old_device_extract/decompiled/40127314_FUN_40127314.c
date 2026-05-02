// Function : FUN_40127314
// Address  : 0x40127314
// Size     : 503 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40127314(int param_1,int param_2,undefined4 param_3,undefined1 *param_4,int param_5,
                 int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int in_t0;
  int iStack_38c;
  undefined1 *puStack_374;
  int iStack_370;
  int iStack_36c;
  undefined4 uStack_368;
  undefined1 auStack_364 [64];
  undefined1 auStack_324 [768];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_40128a30(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  iVar2 = FUN_40128a30(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
  iVar8 = 1;
  if (iVar1 == 0) goto LAB_4012735a;
  iStack_38c = param_2;
  if (iVar2 == 0) goto LAB_4012735a;
  do {
    uVar7 = *(uint *)(param_1 + 0x10);
    if (uVar7 < 0x201) {
      iVar6 = (uVar7 + 1 >> 1) + uVar7;
      memw();
      iVar3 = FUN_401857d0(uVar7);
      puStack_374 = param_4;
      iStack_36c = param_5;
      if (param_6 != 0) {
        memw();
        iStack_370 = param_6;
        uStack_368 = (*(code *)&SUB_4008c01c)(param_6);
        iVar8 = 2;
      }
      param_6 = in_t0;
      in_t0 = param_6;
      if (iVar3 != 0x20) goto LAB_4012735a;
      memw();
      iVar5 = FUN_401020e4(iStack_38c,param_3,iVar8,&puStack_374,&iStack_36c,auStack_364);
      in_t0 = param_6;
      if ((iVar5 < 0) ||
         (iVar5 = FUN_40125fd0(0x20,auStack_364,0x20,"Pecking",auStack_324,iVar6), iVar8 = iVar3,
         in_t0 = param_6, iVar5 < 0)) goto LAB_4012735a;
      iVar8 = FUN_40128a30(auStack_324,iVar6);
      iStack_38c = FUN_40128a58(1);
      memw();
      iVar6 = FUN_40128a58(2);
      iVar5 = FUN_40128a18();
      if ((((iVar8 == 0) || (iStack_38c == 0)) || (iVar6 == 0)) || (iVar5 == 0)) {
LAB_401274d2:
        param_1 = 0;
      }
      else {
        iVar3 = iVar5;
        iVar4 = FUN_40128b3c(iVar1,iVar6);
        param_1 = 0;
        if (((-1 < iVar4) && (iVar3 = iVar8, iVar4 = FUN_40128af0(iVar8,iVar5), -1 < iVar4)) &&
           (iVar3 = iVar8, iVar4 = FUN_40128ad8(iVar8,iVar6), -1 < iVar4)) {
          iVar3 = 0x300;
          iVar4 = FUN_40128a90(iVar8,auStack_324,0x300,uVar7);
          if (-1 < iVar4) {
            param_1 = FUN_40128a18();
            if (((param_1 == 0) ||
                (iVar3 = iVar5, iVar4 = FUN_40128b3c(iVar1,iStack_38c), iVar4 < 0)) ||
               ((iVar3 = iVar5, iVar4 = FUN_40128b54(iVar5,iVar2), iVar4 < 0 ||
                (iVar3 = iVar1, iVar4 = FUN_40128b08(iVar8,iVar5,iVar1,param_1), iVar4 < 0)))) {
              FUN_40128a7c(param_1,1);
              goto LAB_401274d2;
            }
            FUN_40126228(param_1,uVar7);
          }
        }
      }
    }
    else {
LAB_4012735a:
      param_6 = in_t0;
      iVar3 = iVar8;
      param_1 = 0;
      iVar5 = 0;
      iVar8 = 0;
      iVar6 = 0;
      iStack_38c = 0;
    }
    memw();
    FUN_40102884(auStack_364,0x40);
    FUN_40102884(auStack_324,0x300);
    FUN_40128a7c(iVar8,1);
    FUN_40128a7c(iVar5,1);
    FUN_40128a7c(iStack_38c,0);
    FUN_40128a7c(iVar6,0);
    FUN_40128a7c(iVar1,0);
    FUN_40128a7c(iVar2,0);
    param_5 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
    param_4 = &DAT_3ffc5708;
    iVar8 = iVar3;
    in_t0 = param_6;
  } while( true );
}

