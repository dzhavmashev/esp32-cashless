// Function : FUN_4010501c
// Address  : 0x4010501c
// Size     : 302 bytes


void FUN_4010501c(int param_1,uint param_2,char *param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined1 uVar5;
  char *pcVar6;
  uint uVar7;
  char cVar8;
  
  uVar3 = 0;
  do {
    cVar8 = *param_3;
    if ((cVar8 == '\0') || (uVar7 = uVar3 + 1, param_2 <= uVar7)) {
      if (uVar3 < param_2) {
        *(undefined1 *)(param_1 + uVar3) = 0;
        memw();
      }
      memw();
      return;
    }
    pcVar6 = param_3 + 1;
    if (cVar8 != '\\') {
LAB_40105140:
      *(char *)(param_1 + uVar3) = cVar8;
      memw();
      memw();
      uVar3 = uVar7;
      goto LAB_401050da;
    }
    bVar1 = param_3[1];
    if (bVar1 == 0x65) {
      uVar5 = 0x1b;
LAB_401050e8:
      *(undefined1 *)(param_1 + uVar3) = uVar5;
      memw();
      memw();
LAB_401050d8:
      pcVar6 = param_3 + 2;
      uVar3 = uVar7;
    }
    else if (bVar1 < 0x66) {
      if (bVar1 < 0x38) {
        if (0x2f < bVar1) {
          cVar8 = bVar1 - 0x30;
          pcVar6 = param_3 + 2;
          if ((byte)(param_3[2] - 0x30U) < 8) {
            pcVar6 = param_3 + 3;
            cVar8 = (param_3[2] - 0x30U) + cVar8 * '\b';
          }
          cVar2 = *pcVar6;
          if ((byte)(cVar2 - 0x30U) < 8) {
            pcVar6 = pcVar6 + 1;
            cVar8 = (cVar2 - 0x30U) + cVar8 * '\b';
          }
          goto LAB_40105140;
        }
        if (bVar1 == 0x22) {
          uVar5 = 0x22;
          goto LAB_401050d2;
        }
      }
      else if (bVar1 == 0x5c) {
        uVar5 = 0x5c;
LAB_40105079:
        *(undefined1 *)(param_1 + uVar3) = uVar5;
        memw();
        memw();
        goto LAB_401050d8;
      }
    }
    else {
      if (bVar1 == 0x72) {
        uVar5 = 0xd;
        goto LAB_401050e8;
      }
      if (bVar1 < 0x73) {
        if (bVar1 == 0x6e) {
          uVar5 = 10;
LAB_401050d2:
          *(undefined1 *)(param_1 + uVar3) = uVar5;
          memw();
          goto LAB_401050d8;
        }
      }
      else {
        if (bVar1 == 0x74) {
          uVar5 = 9;
          goto LAB_40105079;
        }
        if (bVar1 == 0x78) {
          iVar4 = FUN_40104f58(param_3 + 2);
          if (iVar4 < 0) {
            iVar4 = (*(code *)&LAB_40185007_1)(param_3[2]);
            pcVar6 = param_3 + 2;
            if (-1 < iVar4) {
              *(char *)(param_1 + uVar3) = (char)iVar4;
              memw();
              memw();
              pcVar6 = param_3 + 3;
              uVar3 = uVar7;
            }
          }
          else {
            *(char *)(param_1 + uVar3) = (char)iVar4;
            memw();
            memw();
            pcVar6 = param_3 + 4;
            uVar3 = uVar7;
          }
        }
      }
    }
LAB_401050da:
    param_3 = pcVar6;
    memw();
  } while( true );
}

