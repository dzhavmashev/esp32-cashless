// Function : FUN_40104e04
// Address  : 0x40104e04
// Size     : 335 bytes


undefined4 FUN_40104e04(char *param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = param_1 + param_2;
  (*(code *)&SUB_4008b530)(param_3,0,0x3c);
  pcVar4 = param_1 + param_2 + -1;
  do {
    if ((pcVar5 <= param_1 + 1) ||
       ((cVar1 = *param_1, cVar1 == -0x23 && ((param_1 == pcVar4 || (param_1[1] == '\0')))))) {
      return 0;
    }
    uVar2 = (uint)(byte)param_1[1];
    if (pcVar5 < param_1 + uVar2 + 2) {
      return 0xffffffff;
    }
    if (cVar1 == '0') {
      param_3[2] = param_1;
      param_3[3] = (byte)param_1[1] + 2;
    }
    else if (cVar1 == -0xc) {
      param_3[0xd] = param_1;
      param_3[0xe] = (byte)param_1[1] + 2;
      memw();
    }
    else if (cVar1 == -0x23) {
      if (uVar2 == 0) {
        return 0;
      }
      if (uVar2 < 6) {
LAB_40104ed5:
        if (uVar2 < 7) {
          if (uVar2 < 5) goto LAB_40104e54;
LAB_40104f2e:
          iVar3 = FUN_40184fe4(param_1 + 2);
          if (iVar3 == 0x506f9a20) {
            param_3[0xb] = param_1 + 6;
            param_3[0xc] = (byte)param_1[1] - 4;
            memw();
          }
        }
        else {
LAB_40104ed8:
          iVar3 = FUN_40184fe4(param_1 + 2);
          if (iVar3 == 0xfac01) {
            param_3[5] = param_1 + 6;
            param_3[6] = (byte)param_1[1] - 4;
            memw();
          }
          else if (iVar3 == 0xfac03) {
            param_3[7] = param_1 + 6;
            param_3[8] = (byte)param_1[1] - 4;
            memw();
          }
          else {
            if (iVar3 != 0xfac09) goto LAB_40104f2e;
            param_3[9] = param_1 + 6;
            param_3[10] = (byte)param_1[1] - 4;
            memw();
          }
        }
      }
      else {
        memw();
        iVar3 = FUN_40184fe4(param_1 + 2);
        if (((iVar3 != 0x50f201) || (param_1[6] != '\x01')) || (param_1[7] != '\0')) {
          if ((pcVar5 <= param_1 + 5) || (uVar2 < 0x14)) goto LAB_40104ed5;
          iVar3 = FUN_40184fe4(param_1 + 2);
          if (iVar3 == 0xfac04) {
            param_3[4] = param_1 + 6;
            memw();
            goto LAB_40104e54;
          }
          goto LAB_40104ed8;
        }
        *param_3 = param_1;
        param_3[1] = (byte)param_1[1] + 2;
        memw();
      }
    }
LAB_40104e54:
    param_1 = param_1 + (byte)param_1[1] + 2;
    memw();
  } while( true );
}

