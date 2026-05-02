// Function : FUN_4016fca0
// Address  : 0x4016fca0
// Size     : 692 bytes


undefined4
FUN_4016fca0(int param_1,uint param_2,uint param_3,int param_4,uint *param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint in_t0;
  int local_70;
  int iStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  uint uStack_60;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  int iStack_58;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  int iStack_48;
  uint *puStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  puStack_44 = (uint *)0x0;
  iStack_48 = 0;
  if (param_1 != 1) {
    return 3;
  }
  uStack_3c = param_3 + 0xbcd4d500;
  uStack_34 = (uint)(uStack_3c < param_3) + param_4 + -0x474e5544;
  uStack_30 = 1;
  if ((uStack_34 != 0) || (1 < uStack_3c)) {
    uStack_30 = 0;
  }
  iVar6 = 1;
  uStack_38 = uStack_30 & param_2 == 6;
  if (uStack_38 == 0) {
    uVar4 = FUN_40170f1c(param_6);
    if (uVar4 != 0) {
      uStack_24 = FUN_4016fc38(param_6,uVar4,&local_70);
      uStack_68 = FUN_4016fbc4(uStack_5c,param_6);
      uVar1 = FUN_40170f04(param_6,&iStack_48);
      uVar3 = uStack_24;
      if (iStack_48 == 0) {
        uVar1 = uVar1 - 1;
      }
      do {
        if (uStack_60 <= uVar3) {
          uVar5 = 0;
          uVar1 = 0;
          uVar3 = 0;
          iVar6 = 1;
          goto LAB_4016fe81;
        }
        uVar2 = FUN_4016fc1c(0,uStack_5b,uVar3,&iStack_4c);
        uVar2 = FUN_4016fc1c(0,uStack_5b,uVar2,&uStack_50);
        uVar2 = FUN_4016fc1c(0,uStack_5b,uVar2,&uStack_54);
        uVar5 = FUN_40186e68(uVar2,&iStack_58);
        uVar3 = uStack_60;
      } while ((uVar1 < (uint)(local_70 + iStack_4c)) ||
              (uVar3 = uVar5, local_70 + iStack_4c + uStack_50 <= uVar1));
      uVar1 = uStack_54;
      if (uStack_54 != 0) {
        uVar1 = uStack_54 + iStack_6c;
      }
      if (iStack_58 == 0) {
        if (uVar1 != 0) {
          uVar3 = 0;
          goto LAB_4016fe7f;
        }
      }
      else if (uVar1 != 0) {
        uVar3 = uStack_60 + iStack_58 + -1;
        if (uVar3 != 0) {
          puStack_44 = param_5 + 8;
          if ((*param_5 & 1) != 0) {
            puStack_44 = (uint *)param_5[-0xc];
          }
          uStack_40 = puStack_44[-0x14];
          uStack_28 = param_2 >> 3 & 1 ^ 1;
          do {
            iStack_2c = FUN_40186e90(uVar3,&uStack_50);
            FUN_40186e90(iStack_2c,&uStack_54);
            if (uStack_50 == 0) {
              uStack_38 = 1;
            }
            else {
              if ((int)uStack_50 < 1) {
                if (((uStack_40 == 0) || (uStack_28 == 0)) || (uStack_30 == 0)) {
                  FUN_40186e68(iStack_64 + (uStack_50 ^ 0xffffffff),&iStack_58);
                  uVar5 = (uint)(iStack_58 == 0);
                }
                else {
                  uVar5 = FUN_4016fb8c(&local_70,uStack_40,puStack_44);
                  uVar5 = uVar5 ^ 1;
                }
                uVar5 = uVar5 & 0xff;
              }
              else {
                iVar6 = FUN_4016fb3c(&local_70,uStack_50);
                if (iVar6 == 0) goto LAB_4016ff4d;
                if (uStack_40 == 0) goto LAB_4016fe60;
                uVar5 = FUN_40186ecc(iVar6,uStack_40,&puStack_44);
              }
              if (uVar5 != 0) goto LAB_4016ff4d;
            }
LAB_4016fe60:
            if (uStack_54 == 0) goto LAB_4016ff55;
            uVar3 = iStack_2c + uStack_54;
          } while( true );
        }
LAB_4016fe7f:
        uVar5 = 0;
        iVar6 = 2;
        goto LAB_4016fe81;
      }
    }
  }
  else {
    uVar5 = param_5[-6];
    uVar4 = param_5[-4];
    uVar1 = param_5[-3];
    uVar3 = 3;
    if (uVar1 != 0) {
      iVar6 = 3;
    }
    do {
      if ((((param_2 & 8) == 0) && (param_2 = uStack_34, uStack_34 == 0)) &&
         (uVar3 = uStack_3c, uStack_3c < 2)) {
        if (iVar6 == 1) goto LAB_4016fecd;
LAB_4016fed5:
        if ((int)uVar5 < 0) {
          uStack_24 = uVar5;
          FUN_4016fc38(param_6,uVar4,&local_70);
          uStack_68 = FUN_4016fbc4(uStack_5c,param_6);
          uVar4 = FUN_4016fbc4(uStack_5c,param_6);
          param_5[-3] = uVar4;
          uVar5 = uStack_24;
        }
LAB_4016ff0a:
        uStack_24 = uVar5;
        FUN_40170ee0(param_6,2,param_5);
        FUN_40170ee0(param_6,3,uStack_24);
        FUN_40170f14(param_6,uVar1);
        return 7;
      }
      if (iVar6 != 1) {
        if (-1 < (int)uVar5) goto LAB_4016ff0a;
        FUN_40170214();
LAB_4016fecd:
        uVar5 = in_t0;
        FUN_401705a4(param_5);
        goto LAB_4016fed5;
      }
      FUN_401701ec();
LAB_4016ff4d:
      iVar6 = 3;
      uVar5 = uStack_50;
LAB_4016fe81:
    } while ((param_2 & 1) == 0);
    if (iVar6 != 2) {
      if ((uStack_34 == 0) && (uStack_3c < 2)) {
        param_5[-6] = uVar5;
        param_5[-5] = uVar3;
        param_5[-4] = uVar4;
        param_5[-2] = (uint)puStack_44;
        param_5[-3] = uVar1;
      }
      return 6;
    }
  }
  return 8;
LAB_4016ff55:
  if (uStack_38 == 0) {
    return 8;
  }
  goto LAB_4016fe7f;
}

