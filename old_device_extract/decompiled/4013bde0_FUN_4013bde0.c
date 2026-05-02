// Function : FUN_4013bde0
// Address  : 0x4013bde0
// Size     : 501 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4013bde0(int param_1,int param_2,int param_3,undefined1 *param_4,undefined4 param_5,
                undefined4 param_6,uint *param_7,undefined4 param_8,undefined4 param_9,uint param_10
                )

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_a3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int in_t0;
  undefined1 auStack_470 [12];
  undefined1 auStack_464 [64];
  char cStack_424;
  byte abStack_423 [1023];
  int local_24;
  undefined1 auStack_20 [32];
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  if (param_4 != (undefined1 *)0x1) goto LAB_4013be46;
  if (*(int *)(param_1 + 0xa4) == 1) goto LAB_4013be46;
  do {
    param_1 = in_t0;
    iVar5 = -0x4080;
    while( true ) {
      param_3 = local_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (local_24 == _DAT_3ffc5708) {
        return iVar5;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
      param_8 = extraout_a3;
      in_t0 = param_1;
LAB_4013be46:
      uVar8 = *(uint *)(param_1 + 4);
      if (0x3f0 < uVar8 - 0x10) break;
      memw();
      iVar2 = FUN_40138f28(*(undefined4 *)(param_1 + 0xa8));
      if (iVar2 == 0) break;
      iVar3 = FUN_401864c4();
      if (uVar8 < (uint)((iVar3 + 1) * 2)) break;
      if (param_4 == (undefined1 *)0x0) {
        memw();
        iVar5 = FUN_4013b510(param_1,param_8,&cStack_424);
        param_1 = in_t0;
      }
      else {
        iVar5 = FUN_4013b574(param_1,param_2,param_3,param_8,&cStack_424);
        param_1 = in_t0;
      }
      if (iVar5 == 0) {
        FUN_40138f64(auStack_470);
        iVar5 = FUN_4013905c(auStack_470,iVar2,0);
        if (iVar5 == 0) {
          iVar7 = (uVar8 - 1) - iVar3;
          memw();
          iVar5 = FUN_4013ae6c(abStack_423,iVar3,abStack_423 + iVar3,iVar7,auStack_470);
          if ((iVar5 == 0) &&
             (iVar5 = FUN_4013ae6c(abStack_423 + iVar3,iVar7,abStack_423,iVar3,auStack_470),
             iVar5 == 0)) {
            FUN_40138f78(auStack_470);
            iVar5 = FUN_40139210(iVar2,param_5,param_6,auStack_464);
            cVar1 = cStack_424;
            if (iVar5 == 0) {
              pbVar4 = abStack_423 + iVar3;
              iVar7 = FUN_401862dc(auStack_464,pbVar4,iVar3);
              uVar6 = 0;
              iVar2 = 0;
              for (iVar5 = 0; uVar8 + (iVar3 + 1) * -2 != iVar5; iVar5 = iVar5 + 1) {
                uVar6 = uVar6 | pbVar4[iVar5 + iVar3];
                iVar2 = iVar2 + ((uVar6 | -uVar6) >> 7 & 1 ^ 1);
              }
              if (pbVar4[iVar2 + iVar3] == 1 && (cVar1 == '\0' && iVar7 == 0)) {
                uVar8 = uVar8 - (int)(pbVar4 + ((iVar2 + 1 + iVar3) - (int)&cStack_424));
                if (param_10 < uVar8) {
                  iVar5 = -0x4400;
                }
                else {
                  *param_7 = uVar8;
                  iVar5 = 0;
                  if (uVar8 != 0) {
                    memw();
                    (*(code *)&SUB_4008b3d0)(param_9);
                  }
                }
              }
              else {
                iVar5 = -0x4100;
              }
            }
            goto LAB_4013bef3;
          }
        }
        FUN_40138f78(auStack_470);
      }
LAB_4013bef3:
      param_4 = auStack_20;
      FUN_4013ae54(&cStack_424,0x400);
      FUN_4013ae54(auStack_464,0x40);
    }
  } while( true );
}

