// Function : FUN_4013a108
// Address  : 0x4013a108
// Size     : 772 bytes


int FUN_4013a108(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *local_120;
  int local_11c;
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [12];
  undefined1 auStack_108 [12];
  undefined1 auStack_fc [12];
  undefined1 auStack_f0 [12];
  undefined1 auStack_e4 [12];
  undefined1 auStack_d8 [12];
  undefined1 auStack_cc [12];
  int iStack_c0;
  int iStack_bc;
  int iStack_9c;
  undefined1 auStack_98 [12];
  undefined1 auStack_8c [12];
  undefined1 auStack_80 [12];
  undefined1 auStack_74 [12];
  undefined1 auStack_68 [12];
  undefined1 auStack_5c [12];
  undefined1 auStack_50 [12];
  int iStack_44;
  int iStack_40;
  
  if (*param_1 == 6) {
    iVar1 = FUN_40139534(param_1,&local_11c);
    iVar2 = -0x3a00;
    goto joined_r0x4013a1b7;
  }
  FUN_40135644(auStack_118);
  local_120 = (byte *)param_1[2];
  pbVar5 = local_120 + param_1[1];
  memw();
  iVar2 = FUN_4014180c(&local_120,pbVar5,&iStack_9c);
  if (iVar2 != 0) goto LAB_4013a159;
  if (iStack_9c - 1U < 3) {
    iVar2 = FUN_40141738(&local_120,pbVar5,&local_11c,0x30);
    if (iVar2 == 0) {
      pbVar6 = local_120 + local_11c;
      iVar2 = FUN_40141738(&local_120,pbVar6,&local_11c,6);
      pbVar4 = local_120;
      if (iVar2 == 0) {
        if ((local_11c == 7) &&
           (iVar2 = (*(code *)&SUB_4008b33c)(local_120,&DAT_3f4223d0), iVar2 == 0)) {
          local_120 = pbVar4 + 7;
          memw();
          iVar2 = FUN_40141824(&local_120,pbVar6,auStack_114);
          if (iVar2 != 0) goto LAB_4013a159;
          iStack_c0 = FUN_40131798(auStack_114);
          if (pbVar6 == local_120) {
            memw();
            iVar2 = FUN_40141738(&local_120,pbVar5,&local_11c,0x30);
            if (iVar2 == 0) {
              pbVar4 = local_120 + local_11c;
              iVar2 = FUN_40141738(&local_120,pbVar4,&local_11c);
              if ((iVar2 == 0) &&
                 (iVar2 = FUN_4013183c(auStack_108,local_120,local_11c), iVar2 == 0)) {
                local_120 = local_120 + local_11c;
                memw();
                iVar2 = FUN_40141738(&local_120,pbVar4,&local_11c);
                if ((iVar2 != 0) ||
                   (iVar2 = FUN_4013183c(auStack_fc,local_120,local_11c), iVar2 != 0))
                goto LAB_4013a159;
                local_120 = local_120 + local_11c;
                memw();
                iVar2 = FUN_40141738(&local_120,pbVar4,&local_11c,3);
                if (iVar2 == 0) {
                  local_120 = local_120 + local_11c;
                }
                if (pbVar4 != local_120) goto LAB_4013a359;
                memw();
                iVar2 = FUN_40141738(&local_120,pbVar5,&local_11c,4);
                if (iVar2 != 0) goto LAB_4013a159;
                iVar2 = FUN_40135f68(auStack_118,auStack_f0,local_120,local_11c);
                if ((iVar2 != 0) &&
                   (((((iVar2 != -0x4e80 || (1 < (byte)(*local_120 - 2))) ||
                      (iVar2 = FUN_401317d8(auStack_114), iVar2 + 1 != local_11c)) ||
                     ((iVar2 = FUN_4013183c(auStack_f0,local_120 + 1,iVar2), iVar2 != 0 ||
                      (iVar2 = FUN_40131700(auStack_e4,*local_120 - 2), iVar2 != 0)))) ||
                    (iVar2 = FUN_40131700(auStack_d8,1), iVar2 != 0)))) goto LAB_4013a1a9;
                local_120 = local_120 + local_11c;
                memw();
                iVar2 = FUN_40141824(&local_120,pbVar5,auStack_cc);
                if (iVar2 != 0) goto LAB_4013a159;
                iStack_bc = FUN_40131798(auStack_cc);
                memw();
              }
              else {
LAB_4013a159:
                iVar2 = iVar2 + -0x3d00;
                if (iVar2 != 0) goto LAB_4013a1ac;
              }
              FUN_40135644(&iStack_9c);
              piVar3 = (int *)FUN_401355c4();
              for (; *piVar3 != 0; piVar3 = piVar3 + 1) {
                FUN_401356b4(&iStack_9c);
                iVar2 = FUN_401378f0(&iStack_9c,*piVar3);
                if (iVar2 != 0) goto LAB_4013a3ec;
                if ((((iStack_c0 == iStack_44) && (iStack_bc == iStack_40)) &&
                    ((iVar2 = FUN_401860ec(auStack_114,auStack_98), iVar2 == 0 &&
                     (((iVar2 = FUN_401860ec(auStack_108,auStack_8c), iVar2 == 0 &&
                       (iVar2 = FUN_401860ec(auStack_fc,auStack_80), iVar2 == 0)) &&
                      (iVar2 = FUN_401860ec(auStack_cc,auStack_50), iVar2 == 0)))))) &&
                   ((iVar2 = FUN_401860ec(auStack_f0,auStack_74), iVar2 == 0 &&
                    (iVar2 = FUN_401860ec(auStack_d8,auStack_5c), iVar2 == 0)))) {
                  iVar2 = FUN_4018601c(auStack_e4,0);
                  iVar1 = FUN_4018601c(auStack_68,0);
                  if (iVar2 == iVar1) break;
                }
              }
              iVar2 = 0;
LAB_4013a3ec:
              FUN_401356b4(&iStack_9c);
              local_11c = *piVar3;
              if ((iVar2 == 0) && (local_11c == 0)) {
                iVar2 = -0x4e80;
                memw();
              }
            }
          }
          else {
LAB_4013a359:
            iVar2 = -0x3d66;
          }
        }
        else {
          iVar2 = -0x3980;
        }
      }
    }
  }
  else {
LAB_4013a1a9:
    iVar2 = -0x3d00;
  }
LAB_4013a1ac:
  FUN_401356b4(auStack_118);
  iVar1 = iVar2;
joined_r0x4013a1b7:
  if ((iVar1 == 0) && ((*param_2 == 0 || (iVar2 = -0x3d00, *param_2 == local_11c)))) {
    iVar2 = FUN_401378f0(param_2);
  }
  return iVar2;
}

