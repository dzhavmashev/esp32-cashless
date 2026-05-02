// Function : FUN_40132650
// Address  : 0x40132650
// Size     : 701 bytes


int FUN_40132650(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  uint *puStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint *puStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint *puStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint *puStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint *puStack_24;
  
  iVar1 = FUN_40131ad8(param_3,1);
  if (iVar1 < 1) {
    return -4;
  }
  uStack_80 = 1;
  uStack_7c = 0;
  uStack_78 = 0;
  uStack_74 = 1;
  uStack_70 = 0;
  puStack_6c = (uint *)0x0;
  uStack_68 = 1;
  uStack_64 = 0;
  puStack_60 = (uint *)0x0;
  uStack_5c = 1;
  uStack_58 = 0;
  puStack_54 = (uint *)0x0;
  uStack_8c = 1;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_50 = 1;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 1;
  uStack_40 = 0;
  puStack_3c = (uint *)0x0;
  uStack_38 = 1;
  uStack_34 = 0;
  puStack_30 = (uint *)0x0;
  uStack_2c = 1;
  uStack_28 = 0;
  puStack_24 = (uint *)0x0;
  memw();
  iVar1 = FUN_401322b4(&uStack_8c,param_2,param_3);
  if (iVar1 == 0) {
    iVar2 = FUN_40131ad8(&uStack_8c,1);
    iVar1 = -0xe;
    if (((((iVar2 == 0) && (iVar1 = FUN_401320e0(&uStack_80,param_2,param_3), iVar1 == 0)) &&
         (iVar1 = FUN_4013167c(&uStack_74,&uStack_80), iVar1 == 0)) &&
        ((iVar1 = FUN_4013167c(&uStack_50,param_3), iVar1 == 0 &&
         (iVar1 = FUN_4013167c(&uStack_44,param_3), iVar1 == 0)))) &&
       ((iVar1 = FUN_40131700(&uStack_68,1), iVar1 == 0 &&
        ((iVar1 = FUN_40131700(&uStack_5c), iVar1 == 0 &&
         (iVar1 = FUN_40131700(&uStack_38), iVar1 == 0)))))) {
      iVar1 = FUN_40131700(&uStack_2c,1);
      while (iVar1 == 0) {
        while ((*puStack_6c & 1) != 0) {
          while ((*puStack_3c & 1) == 0) {
            iVar1 = FUN_40131a34(&uStack_44,1);
            if ((iVar1 != 0) ||
               (((((*puStack_30 & 1) != 0 || ((*puStack_24 & 1) != 0)) &&
                 ((iVar1 = FUN_40131d18(&uStack_38,&uStack_38,&uStack_50), iVar1 != 0 ||
                  (iVar1 = FUN_40131d30(&uStack_2c,&uStack_2c,&uStack_80), iVar1 != 0)))) ||
                ((iVar1 = FUN_40131a34(&uStack_38,1), iVar1 != 0 ||
                 (iVar1 = FUN_40131a34(&uStack_2c,1), iVar1 != 0)))))) goto LAB_401327e5;
          }
          iVar1 = FUN_401860ec(&uStack_74,&uStack_44);
          if (iVar1 < 0) {
            iVar1 = FUN_40131d30(&uStack_44,&uStack_44,&uStack_74);
            if ((iVar1 != 0) || (iVar1 = FUN_40131d30(&uStack_38,&uStack_38,&uStack_68), iVar1 != 0)
               ) goto LAB_401327e5;
            puVar4 = &uStack_5c;
            puVar3 = &uStack_2c;
          }
          else {
            iVar1 = FUN_40131d30(&uStack_74,&uStack_74,&uStack_44);
            if ((iVar1 != 0) || (iVar1 = FUN_40131d30(&uStack_68,&uStack_68,&uStack_38), iVar1 != 0)
               ) goto LAB_401327e5;
            puVar4 = &uStack_2c;
            puVar3 = &uStack_5c;
          }
          iVar1 = FUN_40131d30(puVar3,puVar3,puVar4);
          if (iVar1 != 0) goto LAB_401327e5;
          iVar1 = FUN_40131ad8(&uStack_74,0);
          if (iVar1 == 0) goto LAB_40132792;
        }
        iVar1 = FUN_40131a34(&uStack_74,1);
        if (((iVar1 != 0) ||
            ((((*puStack_60 & 1) != 0 || ((*puStack_54 & 1) != 0)) &&
             ((iVar1 = FUN_40131d18(&uStack_68,&uStack_68,&uStack_50), iVar1 != 0 ||
              (iVar1 = FUN_40131d30(&uStack_5c,&uStack_5c,&uStack_80), iVar1 != 0)))))) ||
           (iVar1 = FUN_40131a34(&uStack_68,1), iVar1 != 0)) break;
        iVar1 = FUN_40131a34(&uStack_5c,1);
      }
    }
  }
  goto LAB_401327e5;
  while (iVar1 = FUN_40131d18(&uStack_38,&uStack_38,param_3), iVar1 == 0) {
LAB_40132792:
    iVar1 = FUN_40131ad8(&uStack_38,0);
    if (-1 < iVar1) goto LAB_4013279d;
  }
  goto LAB_401327e5;
  while (iVar1 = FUN_40131d30(&uStack_38,&uStack_38,param_3), iVar1 == 0) {
LAB_4013279d:
    iVar1 = FUN_401860ec(&uStack_38,param_3);
    if (iVar1 < 0) {
      iVar1 = FUN_4013167c(param_1,&uStack_38);
      break;
    }
  }
LAB_401327e5:
  memw();
  FUN_40131548(&uStack_80);
  FUN_40131548(&uStack_74);
  FUN_40131548(&uStack_68);
  FUN_40131548(&uStack_5c);
  FUN_40131548(&uStack_8c);
  FUN_40131548(&uStack_50);
  FUN_40131548(&uStack_44);
  FUN_40131548(&uStack_38);
  FUN_40131548(&uStack_2c);
  return iVar1;
}

