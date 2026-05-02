// Function : FUN_400d490c
// Address  : 0x400d490c
// Size     : 176 bytes


bool FUN_400d490c(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  
  piVar2 = (int *)FUN_400d48f8(*param_1 + 0x18,param_1[1]);
  if (piVar2 == (int *)0x0) {
    cVar1 = param_2 == 0;
  }
  else {
    cVar1 = '\0';
    bVar7 = *(byte *)(piVar2 + 2) & 0x7f;
    if (bVar7 != 6) {
      if (bVar7 < 7) {
        if (1 < bVar7) {
          if (3 < bVar7) {
            uVar5 = piVar2[1];
            if (param_2 == 0) {
              uVar3 = 0;
            }
            else {
              iVar6 = *piVar2;
              uVar3 = func_0x4008c024(param_2);
              for (iVar8 = 0; iVar8 != (uVar5 < uVar3) * uVar5 + (uVar5 >= uVar3) * uVar3;
                  iVar8 = iVar8 + 1) {
                uVar4 = (uint)*(byte *)(iVar6 + iVar8);
                uVar9 = (uint)*(byte *)(param_2 + iVar8);
                if (uVar4 != uVar9) {
                  cVar1 = '\x02';
                  if (((int)(uVar4 - uVar9) < 1) && (cVar1 = '\x04', uVar4 == uVar9)) {
                    cVar1 = '\x01';
                  }
                  goto LAB_400d4930;
                }
              }
              cVar1 = '\x04';
              if (uVar5 < uVar3) goto LAB_400d4930;
            }
            cVar1 = '\x01';
            if (uVar3 < uVar5) {
              cVar1 = '\x02';
            }
          }
          goto LAB_400d4930;
        }
      }
      else {
        cVar1 = '\0';
        if (bVar7 == 0xc) goto LAB_400d4930;
        if (bVar7 < 0xd) {
          cVar1 = '\0';
          if ((bVar7 == 8) || (bVar7 == 10)) goto LAB_400d4930;
        }
        else {
          cVar1 = '\0';
          if ((bVar7 == 0x20) || (bVar7 == 0x40)) goto LAB_400d4930;
        }
      }
      cVar1 = param_2 == 0;
    }
  }
LAB_400d4930:
  return cVar1 != '\x01';
}

