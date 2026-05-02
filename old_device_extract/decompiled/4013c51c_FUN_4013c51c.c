// Function : FUN_4013c51c
// Address  : 0x4013c51c
// Size     : 483 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013c51c(int param_1,int param_2,int param_3,undefined1 *param_4,int param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  undefined1 auStack_74 [12];
  undefined1 auStack_68 [14];
  undefined1 auStack_5a [54];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (*(code *)&SUB_4008b3d0)(auStack_5a,"EY-----");
  if (param_4 == (undefined1 *)0x0) goto LAB_4013c54e;
  iVar3 = 1;
  if (param_5 == 0) goto LAB_4013c54e;
  do {
    if ((((*(int *)(param_4 + 8) == 0) && (*(int *)(param_5 + 8) == 0)) &&
        (iVar2 = FUN_40131ad8(param_1), 0 < iVar2)) &&
       (((iVar2 = FUN_40131ad8(param_3,iVar3), 0 < iVar2 &&
         (iVar2 = FUN_401860ec(param_3,param_1), iVar2 < 0)) &&
        ((iVar3 = FUN_40131ad8(param_2,iVar3), 0 < iVar3 &&
         (iVar3 = FUN_401860ec(param_2,param_1), iVar3 < 0)))))) {
      FUN_40186008(auStack_68);
      FUN_40186008(auStack_74);
      iVar3 = FUN_4013d5d8(auStack_74,param_3,param_2);
      if ((iVar3 == 0) && (iVar3 = FUN_40131d74(auStack_74,auStack_74,1), iVar3 == 0)) {
        uVar1 = FUN_40186044(auStack_74);
        if (uVar1 != 0) {
          iVar3 = FUN_40131a34(auStack_74,uVar1);
          if (iVar3 != 0) goto LAB_4013c5e1;
          uVar4 = (uint)((**(uint **)(param_1 + 8) & 7) == 1);
          do {
            iVar3 = FUN_40131700(auStack_68,auStack_5a[uVar4]);
            if ((iVar3 != 0) || (iVar3 = FUN_401322b4(param_4,auStack_68,param_1), iVar3 != 0))
            goto LAB_4013c5e1;
            iVar3 = FUN_40131ad8(param_4,1);
            if (iVar3 == 0) {
              iVar3 = FUN_4013d3d8(auStack_68,auStack_68,auStack_74,param_1,param_5);
              if (iVar3 != 0) goto LAB_4013c5e1;
              uVar5 = 1;
              do {
                iVar3 = FUN_40131ad8(auStack_68,1);
                if (iVar3 == 0) break;
                iVar3 = FUN_40131d48(auStack_68,auStack_68,1);
                if ((iVar3 != 0) || (iVar3 = FUN_401322b4(param_4,auStack_68,param_1), iVar3 != 0))
                goto LAB_4013c5e1;
                iVar3 = FUN_40131ad8(param_4,1);
                if ((iVar3 == 1) && (iVar3 = FUN_401860ec(param_4,param_1), iVar3 == -1)) {
                  iVar3 = FUN_40131da0(param_5,0,param_1,param_4);
                  goto LAB_4013c5e1;
                }
                iVar3 = FUN_40131d74(auStack_68,auStack_68,1);
                if (((iVar3 != 0) || (iVar3 = FUN_4013d5d8(auStack_68,auStack_68), iVar3 != 0)) ||
                   (iVar3 = FUN_401320e0(auStack_68,auStack_68,param_1), iVar3 != 0))
                goto LAB_4013c5e1;
                uVar5 = uVar5 + 1;
              } while (uVar5 <= uVar1);
              iVar3 = FUN_40131ad8(auStack_68,1);
              if (iVar3 != 0) break;
            }
            uVar4 = uVar4 + 1;
          } while ((uVar4 & 0xffff) < 0x36);
        }
        iVar3 = -4;
      }
LAB_4013c5e1:
      memw();
      FUN_40131548(auStack_68);
      FUN_40131548(auStack_74);
      param_1 = iVar3;
    }
    else {
LAB_4013c54e:
      param_1 = -4;
    }
    param_3 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
    param_4 = &DAT_3ffc5708;
    iVar3 = param_1;
  } while( true );
}

