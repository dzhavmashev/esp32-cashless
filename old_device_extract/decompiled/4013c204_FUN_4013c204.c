// Function : FUN_4013c204
// Address  : 0x4013c204
// Size     : 507 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013c204(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,uint param_10)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uStack_488;
  undefined1 auStack_478 [12];
  undefined4 uStack_46c;
  undefined4 uStack_468;
  undefined1 auStack_464 [63];
  char acStack_425 [16];
  char acStack_415 [1009];
  int local_24;
  
  memw();
  memw();
  local_24 = _DAT_3ffc5708;
  uStack_488 = param_6;
  if (param_4 != (char *)0x1) goto LAB_4013c25e;
  if (*(int *)(param_1 + 0xa4) == 1) goto LAB_4013c25e;
LAB_4013c23d:
  iVar2 = -0x4080;
LAB_4013c240:
  do {
    do {
      param_1 = iVar2;
      param_5 = _DAT_3ffc5708;
      memw();
      memw();
      if (local_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      (*(code *)&SUB_40082ec4)();
LAB_4013c25e:
      pcVar7 = *(char **)(param_1 + 4);
      if ((char *)0x3f0 < pcVar7 + -0x10) goto LAB_4013c23d;
      if (param_4 == (char *)0x0) {
        iVar2 = FUN_4013b510(param_1,param_10,acStack_425 + 1);
      }
      else {
        iVar2 = FUN_4013b574(param_1);
      }
    } while (iVar2 != 0);
    param_4 = pcVar7 + -1;
    iVar2 = -0x4100;
  } while ((acStack_425 + 1)[(int)param_4] != -0x44);
  if (param_5 != 0) {
    iVar2 = FUN_40138f28(param_5);
    if (iVar2 == 0) goto LAB_4013c23d;
    uStack_488 = FUN_401864c4();
  }
  memw();
  iVar2 = FUN_40138f28(param_8);
  if (iVar2 == 0) goto LAB_4013c23d;
  memw();
  uVar3 = FUN_401864c4();
  uStack_46c = 0;
  uStack_468 = 0;
  memw();
  iVar4 = FUN_40131798(param_1 + 8);
  uVar6 = iVar4 - 1;
  if ((int)(uint)(byte)acStack_425[1] >> (uVar6 + (int)pcVar7 * -8 + 8 & 0x1f) != 0)
  goto LAB_4013c23d;
  pcVar5 = acStack_425 + 1;
  if ((uVar6 & 7) == 0) {
    pcVar5 = acStack_425 + 2;
    pcVar7 = param_4;
  }
  param_4 = (char *)(uVar3 + 2);
  if (pcVar7 < param_4) goto LAB_4013c23d;
  memw();
  FUN_40138f64(auStack_478);
  iVar2 = FUN_4013905c(auStack_478,iVar2,0);
  if (iVar2 == 0) {
    param_4 = pcVar5 + (int)(pcVar7 + (uVar3 ^ 0xffffffff));
    param_10 = uVar3;
    iVar2 = FUN_4013ae6c(pcVar5,pcVar7 + (uVar3 ^ 0xffffffff),param_4,uVar3,auStack_478);
    if (iVar2 == 0) {
      acStack_425[1] = (byte)(0xff >> ((int)pcVar7 * 8 - uVar6 & 0x1f)) & acStack_425[1];
      memw();
      do {
        cVar1 = *pcVar5;
        pcVar7 = pcVar5 + 1;
        if (param_4 + -1 <= pcVar5) break;
        pcVar5 = pcVar7;
      } while (cVar1 == '\0');
      iVar2 = -0x4100;
      if ((cVar1 == '\x01') && ((param_9 == -1 || ((int)param_4 - (int)pcVar7 == param_9)))) {
        memw();
        iVar2 = FUN_40139114(auStack_478);
        if ((iVar2 == 0) &&
           ((((iVar2 = FUN_40139174(auStack_478,&uStack_46c,8), iVar2 == 0 &&
              (iVar2 = FUN_40139174(auStack_478,param_7,uStack_488), iVar2 == 0)) &&
             (iVar2 = FUN_40139174(auStack_478,pcVar7,(int)param_4 - (int)pcVar7), iVar2 == 0)) &&
            (iVar2 = FUN_401391c4(auStack_478,auStack_464), iVar2 == 0)))) {
          iVar4 = (*(code *)&SUB_4008b33c)(param_4,auStack_464,uVar3);
          iVar2 = 0;
          if (iVar4 != 0) {
            iVar2 = -0x4380;
          }
        }
      }
    }
  }
  memw();
  FUN_40138f78(auStack_478);
  goto LAB_4013c240;
}

