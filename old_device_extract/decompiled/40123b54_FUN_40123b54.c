// Function : FUN_40123b54
// Address  : 0x40123b54
// Size     : 371 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40123b54(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined1 auStack_26 [38];
  
  if (param_2 == 1) {
    iVar5 = FUN_4015a9bc();
    if (iVar5 == 0) {
      uVar1 = FUN_4015a08c();
      puVar2 = (undefined4 *)FUN_40159fac();
      iVar5 = FUN_40159fe8();
      if ((iVar5 != 0) && (_DAT_3ffc7658 == 0)) {
        memw();
        uVar3 = (*(code *)&SUB_4008c01c)(uVar1);
        _DAT_3ffc7658 = FUN_40127844(0x3ffbf740,puVar2 + 1,*puVar2,uVar1,uVar3,0);
      }
      memw();
      iVar4 = FUN_40104604();
      if (iVar4 == 0) {
        if (_DAT_3ffc75fc != 0) {
          FUN_4010531c();
          _DAT_3ffc75fc = 0;
        }
        if (_DAT_3ffc7600 == 0) {
          (*(code *)&SUB_4008b530)(&DAT_3ffc7604,0,0x54);
          iVar4 = FUN_40127254(&DAT_3ffc7604,0x13);
          if (iVar4 == 0) {
            memw();
            FUN_4015a5a0(0,auStack_26);
            if (param_1 != 0) {
              if (iVar5 == 0) {
                uVar3 = (*(code *)&SUB_4008c01c)(uVar1);
                iVar5 = FUN_40127adc(auStack_26,param_1,uVar1,uVar3,&DAT_3ffc7604);
              }
              else {
                iVar5 = FUN_40127b44(&DAT_3ffc7604,_DAT_3ffc7658,auStack_26,param_1);
              }
              if (-1 < iVar5) {
                iVar5 = 0;
                goto LAB_40123bd1;
              }
            }
          }
        }
        else {
          iVar5 = *(int *)(_DAT_3ffc7600 + 4);
LAB_40123bd1:
          memw();
          _DAT_3ffc75fc = FUN_401052d0(iVar5 + 0x701);
          if (_DAT_3ffc75fc != 0) {
            memw();
            iVar5 = FUN_40127f54(&DAT_3ffc7604,_DAT_3ffc75fc,_DAT_3ffc7600,0);
            piVar6 = (int *)&DAT_3ffc75fc;
            if (iVar5 != 0) goto LAB_40123bfa;
            if (_DAT_3ffc7600 != 0) {
              FUN_4010531c();
              _DAT_3ffc7600 = 0;
            }
            piVar6 = (int *)&DAT_3ffc75fc;
            _DAT_3ffc7604 = 1;
            goto LAB_40123c62;
          }
        }
        goto LAB_40123b60;
      }
    }
    uVar1 = 0;
    *param_3 = 0;
  }
  else {
    if ((param_2 == 2) && (_DAT_3ffc7604 == 1)) {
      if (_DAT_3ffc75f8 != 0) {
        FUN_4010531c();
        _DAT_3ffc75f8 = 0;
      }
      memw();
      _DAT_3ffc75f8 = FUN_401052d0(0x701);
      if (_DAT_3ffc75f8 != 0) {
        memw();
        piVar6 = (int *)&DAT_3ffc75f8;
        iVar5 = FUN_401284e0(&DAT_3ffc7604,_DAT_3ffc75f8);
        if (iVar5 != 0) {
LAB_40123bfa:
          uVar1 = 0;
          FUN_4010531c(*piVar6);
          *piVar6 = 0;
          memw();
          goto LAB_40123b6e;
        }
        _DAT_3ffc7604 = 2;
LAB_40123c62:
        uVar1 = *(undefined4 *)(*piVar6 + 8);
        *param_3 = *(undefined4 *)(*piVar6 + 4);
        memw();
        goto LAB_40123b6e;
      }
    }
LAB_40123b60:
    uVar1 = 0;
  }
LAB_40123b6e:
  memw();
  return uVar1;
}

